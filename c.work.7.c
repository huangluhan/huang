#include <stdio.h>

void matrix_multi(double A[3][4], double B[4][5], double C[3][5]) {
    //将矩阵c中的元素初始化为0
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            C[i][j] = 0;
        }
    }

    //计算矩阵c中元素
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 5; j++) { 
            for (int k = 0; k < 4; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


int main() {
    //测试函数正确性
    double A[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    double B[4][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}};
    double C[3][5];

    matrix_multi(A, B, C);

    //打印结果
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%f ", C[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
