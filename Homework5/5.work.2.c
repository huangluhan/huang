#include <stdio.h>
#include <stdlib.h>

// 棋盘大小
#define BOARD_SIZE 15

// 初始化棋盘
void initBoard(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '+';
        }
    }
}

// 打印棋盘
void printBoard(char board[][BOARD_SIZE]) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}

// 判断是否落子位置合法
int isLegalMove(char board[][BOARD_SIZE], int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return 0;
    }
    if (board[row][col]!= '+') {
        return 0;
    }
    return 1;
}

// 判断是否有玩家获胜
int checkWin(char board[][BOARD_SIZE], char player) {
    // 检查行
    for (int i = 0; i < BOARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player) {
                count++;
                if (count == 5) {
                    return 1;
                }
            } else {
                count = 0;
            }
        }
    }

    // 检查列
    for (int j = 0; j < BOARD_SIZE; j++) {
        int count = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[i][j] == player) {
                count++;
                if (count == 5) {
                    return 1;
                }
            } else {
                count = 0;
            }
        }
    }

    // 检查主对角线
    for (int k = 0; k < BOARD_SIZE - 4; k++) {
        int count = 0;
        for (int i = k, j = 0; i < BOARD_SIZE && j < BOARD_SIZE; i++, j++) {
            if (board[i][j] == player) {
                count++;
                if (count == 5) {
                    return 1;
                }
            } else {
                count = 0;
            }
        }
    }
    for (int k = 1; k < BOARD_SIZE - 4; k++) {
        int count = 0;
        for (int i = 0, j = k; i < BOARD_SIZE && j < BOARD_SIZE; i++, j++) {
            if (board[i][j] == player) {
                count++;
                if (count == 5) {
                    return 1;
                }
            } else {
                count = 0;
            }
        }
    }

    // 检查副对角线
    for (int k = 0; k < BOARD_SIZE - 4; k++) {
        int count = 0;
        for (int i = k, j = BOARD_SIZE - 1; i < BOARD_SIZE && j >= 0; i++, j--) {
            if (board[i][j] == player) {
                count++;
                if (count == 5) {
                    return 1;
                }
            } else {
                count = 0;
            }
        }
    }
    for (int k = 1; k < BOARD_SIZE - 4; k++) {
        int count = 0;
        for (int i = 0, j = BOARD_SIZE - 1 - k; i < BOARD_SIZE && j >= 0; i++, j--) {
            if (board[i][j] == player) {
                count++;
                if (count == 5) {
                    return 1;
                }
            } else {
                count = 0;
            }
        }
    }

    return 0;
}

// 游戏主函数
int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initBoard(board);
    char currentPlayer = 'X';
    int gameOver = 0;

    printf("欢迎来到五子棋双人对战游戏！\n");
    printBoard(board);

    while (!gameOver) {
        int row, col;
        printf("玩家 %c 请输入落子的行和列（用空格隔开）：", currentPlayer);
        scanf("%d %d", &row, &col);

        if (!isLegalMove(board, row, col)) {
            printf("非法落子，请重新输入！\n");
            continue;
        }

        board[row][col] = currentPlayer;
        printBoard(board);

        if (checkWin(board, currentPlayer)) {
            printf("玩家 %c 获胜！游戏结束。\n", currentPlayer);
            gameOver = 1;
        } else {
            currentPlayer = (currentPlayer == 'X')? 'O' : 'X';
        }
    }

    return 0;
}
