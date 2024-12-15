#include <stdio.h>

// 交换函数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 非递归选择排序函数
void selectionSort(int arr[], int n) {
    int i, j, minIndex;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex!= i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

// 非递归冒泡排序函数
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// 打印数组函数
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100];
    int n;
    int choice;

    printf("请输入数组元素的个数（最多100个）：");
    scanf("%d", &n);

    printf("请输入数组的元素：\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("请选择排序算法：\n");
    printf("1. 选择排序\n");
    printf("2. 冒泡排序\n");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        selectionSort(arr, n);
        printf("选择排序后的数组：\n");
        break;
    case 2:
        bubbleSort(arr, n);
        printf("冒泡排序后的数组：\n");
        break;
    default:
        printf("无效的选择，请重新运行程序。\n");
        return 1;
    }

    printArray(arr, n);

    return 0;
}
