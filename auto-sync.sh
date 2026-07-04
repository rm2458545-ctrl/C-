#!/bin/bash
# 自动同步脚本 - 监控文件变化并自动提交到GitHub
# 改进版：更好的错误处理和兼容性

WATCH_DIR="D:/Zclaude"
LOG_FILE="$WATCH_DIR/.sync-log.txt"
LOCK_FILE="$WATCH_DIR/.sync-lock"

# 确保使用Git Bash环境
if ! command -v git &> /dev/null; then
    echo "错误：找不到git命令，请确保Git Bash已安装" | tee -a "$LOG_FILE"
    exit 1
fi

echo "开始监控文件变化..." | tee -a "$LOG_FILE"
echo "监控目录: $WATCH_DIR" | tee -a "$LOG_FILE"
echo "按 Ctrl+C 停止监控" | tee -a "$LOG_FILE"
echo "----------------------------------------" | tee -a "$LOG_FILE"

# 创建锁文件防止重复运行
if [ -f "$LOCK_FILE" ]; then
    # 检查锁文件是否过期（超过10分钟）
    lock_time=$(stat -c %Y "$LOCK_FILE" 2>/dev/null || echo 0)
    current_time=$(date +%s)
    if (( current_time - lock_time > 600 )); then
        echo "锁文件过期，清理中..." | tee -a "$LOG_FILE"
        rm -f "$LOCK_FILE"
    else
        echo "监控脚本已在运行中（锁文件存在）" | tee -a "$LOG_FILE"
        echo "如需强制运行，请删除: $LOCK_FILE" | tee -a "$LOG_FILE"
        exit 1
    fi
fi
echo $$ > "$LOCK_FILE"

# 清理函数
cleanup() {
    rm -f "$LOCK_FILE"
    echo "" | tee -a "$LOG_FILE"
    echo "监控已停止" | tee -a "$LOG_FILE"
    exit 0
}

trap cleanup SIGINT SIGTERM EXIT

# 使用find和stat监控文件变化
LAST_HASH=""

while true; do
    # 计算当前目录的哈希值（基于文件列表和修改时间）
    CURRENT_HASH=$(find "$WATCH_DIR" -type f \
        -not -path "*/.*" \
        -not -name "*.sh" \
        -not -name "*.log" \
        -not -name "*.lock" \
        -exec stat -c "%Y %n" {} \; 2>/dev/null | sort | md5sum | cut -d' ' -f1)

    if [ "$CURRENT_HASH" != "$LAST_HASH" ] && [ -n "$LAST_HASH" ]; then
        TIMESTAMP=$(date '+%Y/%m/%d %H:%M:%S')
        echo "[$TIMESTAMP] 检测到文件变化，开始同步..." | tee -a "$LOG_FILE"

        # 等待文件写入完成
        sleep 3

        # 执行同步
        cd "$WATCH_DIR" || {
            echo "[$TIMESTAMP] ❌ 无法进入目录" | tee -a "$LOG_FILE"
            continue
        }

        # 检查网络连接
        if ! git ls-remote origin &>/dev/null; then
            echo "[$TIMESTAMP] ❌ 网络连接失败，跳过本次同步" | tee -a "$LOG_FILE"
            continue
        fi

        git add -A
        CHANGES=$(git status --porcelain)

        if [ -n "$CHANGES" ]; then
            # 生成提交信息
            file_count=$(echo "$CHANGES" | wc -l)
            commit_msg="auto-sync: $TIMESTAMP ($file_count 个文件)"

            if git commit -m "$commit_msg" >> "$LOG_FILE" 2>&1; then
                # 尝试推送，最多重试3次
                for attempt in 1 2 3; do
                    if git push origin main >> "$LOG_FILE" 2>&1; then
                        echo "[$TIMESTAMP] ✅ 同步成功" | tee -a "$LOG_FILE"
                        break
                    else
                        if [ $attempt -lt 3 ]; then
                            echo "[$TIMESTAMP] ⚠️ 推送失败，5秒后重试 ($attempt/3)..." | tee -a "$LOG_FILE"
                            sleep 5
                        else
                            echo "[$TIMESTAMP] ❌ 推送失败（已重试3次）" | tee -a "$LOG_FILE"
                        fi
                    fi
                done
            else
                echo "[$TIMESTAMP] ❌ 提交失败" | tee -a "$LOG_FILE"
            fi
        else
            echo "[$TIMESTAMP] 无实际变化，跳过" | tee -a "$LOG_FILE"
        fi
    fi

    LAST_HASH="$CURRENT_HASH"
    sleep 5  # 每5秒检查一次
done
