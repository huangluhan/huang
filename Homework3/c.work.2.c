#include <stdio.h>
#include <stdlib.h>

// 计算一行字符的ASCII码之和
int sumAsciiRow(const char *row, int col) {
    int sum = 0;
    for (int i = 0; i < col; i++) {
        sum += (int)row[i];
    }
    return sum;
}

// 交换两行字符数组
void swapRows(char (*a)[6], char (*b)[6]) {
    char temp[6];
    for (int i = 0; i < 6; i++) {
        temp[i] = a[0][i];
        a[0][i] = b[0][i];
        b[0][i] = temp[i];
    }
}

// 比较函数
int compareRows(const void *a, const void *b) {
    const char (*rowA)[6] = (const char (*)[6])a;
    const char (*rowB)[6] = (const char (*)[6])b;

    int sumA = sumAsciiRow(rowA[0], 6);
    int sumB = sumAsciiRow(rowB[0], 6);

    if (sumA < sumB) return -1;
    if (sumA > sumB) return 1;

    for (int i = 0; i < 6; i++) {
        if (rowA[0][i] < rowB[0][i]) return -1;
        if (rowA[0][i] > rowB[0][i]) return 1;
    }

    return 0;
}

// 交换两个字符
void swapChars(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// 对每行进行排序
void sortEachRow(char matrix[][6], int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = j + 1; k < 6; k++) {
                if (matrix[i][j] > matrix[i][k]) {
                    swapChars(&matrix[i][j], &matrix[i][k]);
                }
            }
        }
    }
}

int main() {
    char matrix[][6] = {
        {'S', 'D', 'U', 'Y', 'E', 'S'},
        {'C', 'H', 'I', 'N', 'A', '!'},
        {'A', 'F', 'T', 'E', 'R', 'X'},
        {'h', 'e', 'r', 'O', 'a', 'b'},
        {'C', 'y', 'y', 'D', 'S', '!'}
    };

    int rows = sizeof(matrix) / sizeof(matrix[0]);

    // 先根据行的ASCII码之和排序行
    for (int i = 0; i < rows - 1; i++) {
        for (int j = i + 1; j < rows; j++) {
            if (sumAsciiRow(matrix[i], 6) > sumAsciiRow(matrix[j], 6)) {
                swapRows(&matrix[i], &matrix[j]);
            }
        }
    }

    // 再对每行进行排序
    sortEachRow(matrix, rows);

    // 输出排序后的矩阵
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
