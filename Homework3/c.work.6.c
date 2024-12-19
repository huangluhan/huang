#include <stdio.h>

// 补全函数
int two_dim_array_access(int *x, int i, int j, int m, int n, int C) {
    return *(x + (m - i) * C + (n - j));
}

// 测试函数
void test_two_dim_array_access() {
    int A[2][3] = { {1, 2, 3}, {4, 5, 6} };

    // 示例一
    int result1 = two_dim_array_access(&A[0][0], 0, 0, 1, 2, 3);
    if (result1 == 6) {
        printf("two_dim_array_access(&A[0][0], 0, 0, 1, 2, 3) 测试通过，结果为: %d\n", result1);
    } else {
        printf("two_dim_array_access(&A[0][0], 0, 0, 1, 2, 3) 测试失败，结果为: %d\n", result1);
    }

    // 示例二
    int result2 = two_dim_array_access(&A[0][1], 0, 1, 1, 2, 3);
    if (result2 == 6) {
        printf("two_dim_array_access(&A[0][1], 0, 1, 1, 2, 3) 测试通过，结果为: %d\n", result2);
    } else {
        printf("two_dim_array_access(&A[0][1], 0, 1, 1, 2, 3) 测试失败，结果为: %d\n", result2);
    }
}

int main() {
    test_two_dim_array_access();

    return 0;
}
