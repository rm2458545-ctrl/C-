#!/bin/bash
# 自动同步脚本 - 监控文件变化并自动提交到GitHub

WATCH_DIR="D:/Zclaude"
LOG_FILE="$WATCH_DIR/.sync-log.txt"
LOCK_FILE="$WATCH_DIR/.sync-lock"

echo "开始监控文件变化..." | tee -a "$LOG_FILE"
echo "监控目录: $WATCH_DIR" | tee -a "$LOG_FILE"
echo "按 Ctrl+C 停止监控" | tee -a "$LOG_FILE"
echo "----------------------------------------" | tee -a "$LOG_FILE"

# 创建锁文件防止重复运行
if [ -f "$LOCK_FILE" ]; then
    echo "监控脚本已在运行中" | tee -a "$LOG_FILE"
    exit 1
fi
echo $$ > "$LOCK_FILE"

# 清理函数
cleanup() {
    rm -f "$LOCK_FILE"
    echo "" | tee -a "$LOG_FILE"
    echo "监控已停止" | tee -a "$LOG_FILE"
    exit 0
}

trap cleanup SIGINT SIGTERM

# 使用find和stat监控文件变化
LAST_HASH=""

while true; do
    # 计算当前目录的哈希值（基于文件列表和修改时间）
    CURRENT_HASH=$(find "$WATCH_DIR" -type f -not -path "*/.*" -not -name "*.sh" -exec stat -c "%Y %n" {} \; 2>/dev/null | sort | md5sum | cut -d' ' -f1)

    if [ "$CURRENT_HASH" != "$LAST_HASH" ] && [ -n "$LAST_HASH" ]; then
        TIMESTAMP=$(date '+%Y/%m/%d %H:%M:%S')
        echo "[$TIMESTAMP] 检测到文件变化，开始同步..." | tee -a "$LOG_FILE"

        # 等待文件写入完成
        sleep 2

        # 执行同步
        cd "$WATCH_DIR"
        git add -A
        CHANGES=$(git status --porcelain)

        if [ -n "$CHANGES" ]; then
            git commit -m "auto-sync: $TIMESTAMP" >> "$LOG_FILE" 2>&1
            if git push origin main >> "$LOG_FILE" 2>&1; then
                echo "[$TIMESTAMP] ✅ 同步成功" | tee -a "$LOG_FILE"
            else
                echo "[$TIMESTAMP] ❌ 推送失败，将重试..." | tee -a "$LOG_FILE"
                # 重试一次
                sleep 5
                git push origin main >> "$LOG_FILE" 2>&1
            fi
        else
            echo "[$TIMESTAMP] 无实际变化，跳过" | tee -a "$LOG_FILE"
        fi
    fi

    LAST_HASH="$CURRENT_HASH"
    sleep 5  # 每5秒检查一次
done
