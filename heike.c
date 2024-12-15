#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 120
#define HEIGHT 30

void init() {
    initscr(); // 初始化ncurses
    curs_set(0); // 隐藏光标
    noecho(); // 不显示输入的字符
    cbreak(); // 禁用行缓冲
    keypad(stdscr, TRUE); // 允许键盘输入
    timeout(100); // 设置getch()超时
    clear(); // 清屏
}

void addChar(int x, int y, char c) {
    mvaddch(y, x, c);
}

void drawMatrix(int speed) {
    int x, y;
    char chars[] = "01"; // 矩阵中的字符
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int index = rand() % strlen(chars);
            int char_type = chars[index];
            attron(COLOR_PAIR(1));
            if (char_type == '1') {
                addChar(x, y, '#');
            } else {
                addChar(x, y, ' ');
            }
            attroff(COLOR_PAIR(1));
        }
    }
    refresh(); // 刷新屏幕以显示更新
    usleep(speed);
}

int main() {
    init();
    srand(time(0)); // 初始化随机数种子
    if (has_colors() == FALSE) {
        endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK); // 设置字符颜色

    while (1) {
        drawMatrix(10000); // 调整这个值可以改变代码雨的速度
        clear(); // 清屏
    }
    endwin(); // 退出ncurses
    return 0;
}
