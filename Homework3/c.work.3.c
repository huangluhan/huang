#include <stdio.h>

int place[8] = {0}; // 皇后位置
int flag[8] = {1, 1, 1, 1, 1, 1, 1, 1}; // 定义列，初始值表示各列未被皇后占领
int d1[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; // 定义上对角线，初始值表示各对角线未被皇后占领
int d2[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; // 定义下对角线，初始值表示各对角线未被皇后占领
int count = 0; // 记录输出次数

// 输出函数，用于打印当前皇后摆放的棋盘布局以及更新摆放方法个数
void print()
{
    int i, j;

    count++;
    printf("No.%2d\n", count);

    int table[8][8] = {0};
    // 根据皇后位置数组place，将对应位置在棋盘数组中标记为1 
     for (i = 0; i < 8; i++)
    {
        table[i][place[i]] = 1;
    }

    // 遍历棋盘数组并输出棋盘布局
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            printf("%d|", table[i][j]);
        }
        printf("\n");
    }
}

// 递归回溯函数，用于尝试在每一行放置皇后并找到所有可行的摆放方案
int queen(int n)
{
    int col;

    // 遍历每一列，尝试在当前行的每一列放置皇后
    for (col = 0; col < 8; col++)
    {
        // 判断在当前列放置皇后是否会与已放置的皇后在列、上对角线、下对角线产生冲突
        if (flag[col] && d1[n - col + 7] && d2[n + col])
        {
            // 如果不冲突，放置皇后到当前位置
            place[n] = col;

            // 更新相应的标记数组，表示该列、上对角线、下对角线已被皇后占领
            flag[col] = 0;
            d1[n - col + 7] = 0;
            d2[n + col] = 0;

            // 如果还未放置完所有皇后（行数小于7），则递归调用函数继续放置下一行皇后
            if (n < 7)
            {
                queen(n + 1);
            }
            // 打印当前摆放方案的棋盘布局
            else
            {
                
                print();
            }

            // 恢复标记数组的值，尝试其他可能的放置位置
            flag[col] = 1;
            d1[n - col + 7] = 1;
            d2[n + col] = 1;
        }
    }

    return count;
}

int main()
{
    count = queen(0);
    printf("共有%d种方法", count);
    return 0;
}
