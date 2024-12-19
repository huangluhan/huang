#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 棋盘大小
#define BOARD_SIZE 3

// 初始化棋盘
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

// 判断是否落子位置合法
int isLegalMove(char board[][BOARD_SIZE], int row, int col) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return 0;
    }
    if (board[row][col]!=' ') {
        return 0;
    }
    return 1;
}

// 判断是否有玩家获胜
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

// 电脑随机落子
void computerMove(char board[][BOARD_SIZE]) {
    int row, col;
    do {
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
    } while (!isLegalMove(board, row, col));
    board[row][col] = 'O';
}

// 游戏主函数
int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initBoard(board);
    char currentPlayer = 'X';
    int gameOver = 0;
    srand((unsigned int)time(NULL));

    printf("欢迎来到井字棋人机对战游戏！\n");
    printBoard(board);

    while (!gameOver) {
        if (currentPlayer == 'X') {
            int row, col;
            printf("玩家请输入落子的行（0 - 2）和列（0 - 2）坐标，用空格隔开：");
            scanf("%d %d", &row, &col);

            if (!isLegalMove(board, row, col)) {
                printf("非法落子，请重新输入！\n");
                continue;
            }

            board[row][col] = currentPlayer;
        } else {
            computerMove(board);
            printf("电脑落子完毕。\n");
        }

        printBoard(board);

        if (checkWin(board, currentPlayer)) {
            if (currentPlayer == 'X') {
                printf("玩家获胜！游戏结束。\n");
            } else {
                printf("电脑获胜！游戏结束。\n");
            }
            gameOver = 1;
        } else if (isBoardFull(board)) {
            printf("平局！游戏结束。\n");
            gameOver = 1;
        } else {
            currentPlayer = (currentPlayer == 'X')? 'O' : 'X';
        }
    }

    return 0;
}

// 检查棋盘是否已满
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
