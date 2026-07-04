<!DOCTYPE html>
<html lang="zh">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>跑马灯效果</title>
    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }

        body {
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 100vh;
            background: linear-gradient(135deg, #1a1a2e 0%, #16213e 100%);
            font-family: 'Microsoft YaHei', sans-serif;
        }

        .marquee-container {
            width: 80%;
            max-width: 800px;
            background: rgba(255, 255, 255, 0.1);
            border-radius: 12px;
            padding: 20px 30px;
            overflow: hidden;
            position: relative;
            box-shadow: 0 8px 32px rgba(0, 0, 0, 0.3);
        }

        .marquee-content {
            display: inline-block;
            white-space: nowrap;
            animation: marquee 10s linear infinite;
            color: #00d4ff;
            font-size: 28px;
            font-weight: bold;
            text-shadow: 0 0 10px rgba(0, 212, 255, 0.5);
        }

        .marquee-content span {
            margin: 0 50px;
        }

        @keyframes marquee {
            0% {
                transform: translateX(100%);
            }
            100% {
                transform: translateX(-100%);
            }
        }

        .marquee-container::before,
        .marquee-container::after {
            content: '';
            position: absolute;
            top: 0;
            bottom: 0;
            width: 80px;
            z-index: 1;
        }

        .marquee-container::before {
            left: 0;
            background: linear-gradient(to right, rgba(26, 26, 46, 0.9), transparent);
        }

        .marquee-container::after {
            right: 0;
            background: linear-gradient(to left, rgba(26, 26, 46, 0.9), transparent);
        }

        /* 多行跑马灯样式 */
        .multi-marquee {
            margin-top: 40px;
        }

        .marquee-up {
            animation: marquee-up 8s linear infinite;
        }

        @keyframes marquee-up {
            0% {
                transform: translateY(100%);
            }
            100% {
                transform: translateY(-100%);
            }
        }

        .marquee-item {
            color: #ff6b6b;
            font-size: 22px;
            padding: 15px 0;
            text-align: center;
        }

        .controls {
            text-align: center;
            margin-top: 30px;
        }

        .controls button {
            background: linear-gradient(135deg, #00d4ff, #0099cc);
            border: none;
            color: white;
            padding: 12px 30px;
            margin: 0 10px;
            border-radius: 25px;
            cursor: pointer;
            font-size: 16px;
            transition: all 0.3s ease;
        }

        .controls button:hover {
            transform: translateY(-2px);
            box-shadow: 0 5px 20px rgba(0, 212, 255, 0.4);
        }

        .controls button.paused {
            background: linear-gradient(135deg, #ff6b6b, #cc5555);
        }
    </style>
</head>
<body>
    <div style="width: 100%; padding: 20px;">
        <!-- 水平跑马灯 -->
        <div class="marquee-container">
            <div class="marquee-content" id="marquee1">
                <span>欢迎来到跑马灯演示！</span>
                <span>这是一个水平滚动的文字效果</span>
                <span>支持自定义内容和速度</span>
                <span>CSS + JavaScript 实现</span>
            </div>
        </div>

        <!-- 垂直跑马灯 -->
        <div class="marquee-container multi-marquee" style="height: 120px;">
            <div class="marquee-up" id="marquee2">
                <div class="marquee-item">第一条消息：系统维护通知</div>
                <div class="marquee-item">第二条消息：新功能上线啦！</div>
                <div class="marquee-item">第三条消息：欢迎用户反馈</div>
                <div class="marquee-item">第四条消息：版本更新 v2.0</div>
                <div class="marquee-item">第一条消息：系统维护通知</div>
                <div class="marquee-item">第二条消息：新功能上线啦！</div>
            </div>
        </div>

        <!-- 控制按钮 -->
        <div class="controls">
            <button onclick="toggleMarquee('marquee1')">暂停/继续 水平</button>
            <button onclick="toggleMarquee('marquee2')">暂停/继续 垂直</button>
            <button onclick="changeSpeed('marquee1', 5)">加速</button>
            <button onclick="changeSpeed('marquee1', 15)">减速</button>
        </div>
    </div>

    <script>
        // 暂停/继续跑马灯
        function toggleMarquee(id) {
            const element = document.getElementById(id);
            const isPaused = element.style.animationPlayState === 'paused';
            element.style.animationPlayState = isPaused ? 'running' : 'paused';
        }

        // 改变速度
        function changeSpeed(id, duration) {
            const element = document.getElementById(id);
            element.style.animationDuration = duration + 's';
        }

        // 动态添加内容
        function addContent(id, text) {
            const element = document.getElementById(id);
            const span = document.createElement('span');
            span.textContent = text;
            element.appendChild(span);
        }
    </script>
</body>
</html>
