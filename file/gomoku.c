#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 15
#define EMPTY 0
#define PLAYER 1   // 玩家 - 黑棋
#define COMPUTER 2 // 电脑 - 白棋

int board[SIZE][SIZE];

// 棋盘显示字符
const char *pieces[] = {". ", "● ", "○ "};

// 打印棋盘
void printBoard() {
    printf("\n    ");
    for (int i = 0; i < SIZE; i++)
        printf("%2d", i);
    printf("\n");

    for (int i = 0; i < SIZE; i++) {
        printf("  %2d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%s", pieces[board[i][j]]);
        }
        printf("\n");
    }
    printf("\n");
}

// 检查是否在棋盘内
int inBoard(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

// 检查是否获胜 (检查4个方向)
int checkWin(int x, int y, int player) {
    int dirs[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};

    for (int d = 0; d < 4; d++) {
        int count = 1;
        // 正方向
        for (int i = 1; i < 5; i++) {
            int nx = x + dirs[d][0] * i;
            int ny = y + dirs[d][1] * i;
            if (inBoard(nx, ny) && board[nx][ny] == player)
                count++;
            else
                break;
        }
        // 反方向
        for (int i = 1; i < 5; i++) {
            int nx = x - dirs[d][0] * i;
            int ny = y - dirs[d][1] * i;
            if (inBoard(nx, ny) && board[nx][ny] == player)
                count++;
            else
                break;
        }
        if (count >= 5)
            return 1;
    }
    return 0;
}

// 棋型评分表
int scoreLine(int count, int openEnds) {
    if (count >= 5) return 100000;
    if (count == 4) {
        if (openEnds == 2) return 10000;  // 活四
        if (openEnds == 1) return 1000;   // 冲四
    }
    if (count == 3) {
        if (openEnds == 2) return 1000;   // 活三
        if (openEnds == 1) return 100;    // 眠三
    }
    if (count == 2) {
        if (openEnds == 2) return 100;    // 活二
        if (openEnds == 1) return 10;     // 眠二
    }
    if (count == 1) {
        if (openEnds == 2) return 10;
        if (openEnds == 1) return 1;
    }
    return 0;
}

// 评估某个位置对某个玩家的价值
int evaluatePoint(int x, int y, int player) {
    int dirs[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};
    int totalScore = 0;

    for (int d = 0; d < 4; d++) {
        int count = 1;
        int openEnds = 0;

        // 正方向
        int i;
        for (i = 1; i < 5; i++) {
            int nx = x + dirs[d][0] * i;
            int ny = y + dirs[d][1] * i;
            if (inBoard(nx, ny) && board[nx][ny] == player)
                count++;
            else {
                if (inBoard(nx, ny) && board[nx][ny] == EMPTY)
                    openEnds++;
                break;
            }
        }
        if (i < 5 && !inBoard(x + dirs[d][0] * i, y + dirs[d][1] * i))
            ; // 边界不算开口

        // 反方向
        for (i = 1; i < 5; i++) {
            int nx = x - dirs[d][0] * i;
            int ny = y - dirs[d][1] * i;
            if (inBoard(nx, ny) && board[nx][ny] == player)
                count++;
            else {
                if (inBoard(nx, ny) && board[nx][ny] == EMPTY)
                    openEnds++;
                break;
            }
        }

        totalScore += scoreLine(count, openEnds);
    }
    return totalScore;
}

// 电脑AI - 选择最佳落子位置
void computerMove() {
    int bestX = -1, bestY = -1;
    int bestScore = -1;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != EMPTY)
                continue;

            // 如果棋盘为空，下中心
            int isEmpty = 1;
            for (int a = 0; a < SIZE && isEmpty; a++)
                for (int b = 0; b < SIZE && isEmpty; b++)
                    if (board[a][b] != EMPTY) isEmpty = 0;
            if (isEmpty) {
                bestX = SIZE / 2;
                bestY = SIZE / 2;
                board[bestX][bestY] = COMPUTER;
                printf("电脑落子: (%d, %d)\n", bestX, bestY);
                return;
            }

            // 只考虑周围有棋子的位置
            int near = 0;
            for (int di = -2; di <= 2 && !near; di++)
                for (int dj = -2; dj <= 2 && !near; dj++) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di, nj = j + dj;
                    if (inBoard(ni, nj) && board[ni][nj] != EMPTY) near = 1;
                }
            if (!near) continue;

            // 进攻分 + 防守分
            int attackScore = evaluatePoint(i, j, COMPUTER);
            int defendScore = evaluatePoint(i, j, PLAYER);

            // 优先进攻，防守次之
            int score = attackScore * 1.1 + defendScore;

            if (score > bestScore) {
                bestScore = score;
                bestX = i;
                bestY = j;
            }
        }
    }

    if (bestX == -1) {
        // 棋盘满了
        bestX = SIZE / 2;
        bestY = SIZE / 2;
    }

    board[bestX][bestY] = COMPUTER;
    printf("电脑落子: (%d, %d)\n", bestX, bestY);
}

int main() {
    memset(board, 0, sizeof(board));
    srand((unsigned)time(NULL));

    printf("=============================\n");
    printf("      五子棋 - 人机对战\n");
    printf("=============================\n");
    printf("● = 你(黑棋)  ○ = 电脑(白棋)\n");
    printf("输入格式: 行 列 (如: 7 7)\n\n");

    printBoard();

    int turn = 0; // 0=玩家, 1=电脑

    while (1) {
        if (turn == 0) {
            // 玩家回合
            int x, y;
            printf("你的回合 (输入 行 列): ");
            if (scanf("%d %d", &x, &y) != 2) {
                printf("输入错误，请重新输入！\n");
                while (getchar() != '\n');
                continue;
            }

            if (!inBoard(x, y)) {
                printf("超出棋盘范围！请重新输入。\n");
                continue;
            }
            if (board[x][y] != EMPTY) {
                printf("该位置已有棋子！请重新输入。\n");
                continue;
            }

            board[x][y] = PLAYER;
            printBoard();

            if (checkWin(x, y, PLAYER)) {
                printf("🎉 恭喜你赢了！\n");
                break;
            }
            turn = 1;
        } else {
            // 电脑回合
            printf("电脑思考中...\n");
            computerMove();
            printBoard();

            // 找到电脑最后落子位置检查胜负
            for (int i = 0; i < SIZE; i++)
                for (int j = 0; j < SIZE; j++)
                    if (board[i][j] == COMPUTER && checkWin(i, j, COMPUTER)) {
                        printf("💻 电脑获胜！再接再厉！\n");
                        return 0;
                    }
            turn = 0;
        }

        // 检查平局
        int full = 1;
        for (int i = 0; i < SIZE && full; i++)
            for (int j = 0; j < SIZE && full; j++)
                if (board[i][j] == EMPTY) full = 0;
        if (full) {
            printf("平局！棋盘已满。\n");
            break;
        }
    }

    return 0;
}
