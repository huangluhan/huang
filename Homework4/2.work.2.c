#include <stdio.h>
#include "module.h"

int main() {
    // 调用function1并打印返回值
    int result1 = function1();
    printf("function1的返回值：%d\n", result1);
    
    
    // 调用function2并打印返回值
    int result2 = function2();
    printf("function2的返回值：%d\n", result2);

    printf("全局变量global_variable的值：%d\n", global_variable);

    return 0;
}