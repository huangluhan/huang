#include <stdio.h>

int main() {
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int i, j;

    // 按行访问数组元素并输出值
    printf("按行访问数组元素的值：\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("A[%d][%d] = %d\n", i, j, A[i][j]);
        }
    }

    // 按列访问数组元素并输出值
    printf("\n按列访问数组元素的值：\n");
    for (j = 0; j < 3; j++) {
        for (i = 0; i < 2; i++) {
            printf("A[%d][%d] = %d\n", i, j, A[i][j]);
        }
    }

    return 0;
}
