#include <stdio.h>
#include <stdlib.h>

// 定义棋盘大小
#define BOARD_SIZE 3

// 初始化棋盘，用空格表示空白格
void initBoard(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] =' ';
        }
    }
}

// 打印棋盘
void printBoard(char board[][BOARD_SIZE]) {
    printf("  0 1 2\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
            if (j < BOARD_SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) {
            printf("  -----\n");
        }
    }
}

// 检查是否有玩家获胜
int checkWin(char board[][BOARD_SIZE], char player) {
    // 检查行
    for (int i = 0; i < BOARD_SIZE; i++) {
        int win = 1;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j]!= player) {
                win = 0;
                break;
            }
        }
        if (win) return 1;
    }
    // 检查列
    for (int j = 0; j < BOARD_SIZE; j++) {
        int win = 1;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[i][j]!= player) {
                win = 0;
                break;
            }
        }
        if (win) return 1;
    }
    // 检查对角线
    int win = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][i]!= player) {
            win = 0;
            break;
        }
    }
    if (win) return 1;
    win = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][BOARD_SIZE - 1 - i]!= player) {
            win = 0;
            break;
        }
    }
    if (win) return 1;

    return 0;
}

// 检查棋盘是否已满（平局情况）
int isBoardFull(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] ==' ') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initBoard(board);
    char currentPlayer = 'X';
    int moveCount = 0;
    int gameOver = 0;

    printf("欢迎来到井字棋双人对战游戏！\n");
    printBoard(board);

    while (!gameOver) {
        int row, col;
        printf("玩家 %c 请输入行（0 - 2）和列（0 - 2）坐标，用空格隔开：", currentPlayer);
        scanf("%d %d", &row, &col);

        // 检查输入坐标是否合法
        if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col]!=' ') {
            printf("输入坐标不合法，请重新输入！\n");
            continue;
        }

        board[row][col] = currentPlayer;
        moveCount++;
        printBoard(board);

        if (checkWin(board, currentPlayer)) {
            printf("玩家 %c 获胜！游戏结束。\n", currentPlayer);
            gameOver = 1;
        } else if (isBoardFull(board)) {
            printf("平局！游戏结束。\n");
            gameOver = 1;
        }

        // 切换玩家
        currentPlayer = (currentPlayer == 'X')? 'O' : 'X';
    }

    return 0;
}
