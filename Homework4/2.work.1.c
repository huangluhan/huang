#include<stdio.h>
int main(){
    long x = 1;
    // 将字符串常量的地址赋值给x
    ((char **)&x)[0] = "C!YYDS!";
    printf("%s", (char *)x);

    return 0;
}
