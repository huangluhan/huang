#ifndef ANIMATION_H
#define ANIMATION_H

#include <stdio.h>

// 定义颜色代码（简单的ANSI转义序列示例，支持有限）
#define RESET_COLOR "\033[0m"

// 结构体定义物体
typedef struct Object {
    int x;
    int y;
    char shape;
    char color_code[20];  // 存储颜色的转义序列代码
} Object;

// 结构体定义帧（一帧包含多个物体）
typedef struct Frame {
    Object *objects;
    int num_objects;
    struct Frame *next;
} Frame;

// 初始化一个物体
Object init_object(int x, int y, char shape, char *color_code);

// 初始化一帧画面
Frame *init_frame(int num_objects);

// 在终端指定位置输出彩色字符（简单模拟绘制物体）
void draw_object(Object obj);

// 绘制一帧画面（绘制该帧包含的所有物体）
void draw_frame(Frame *frame);

// 释放帧内存（包括帧内物体的内存）
void free_frame(Frame *frame);

// 导出动画（简单以文本格式记录每一帧物体信息到文件）
void export_animation(Frame *head, const char *filename);

// 从文件读取一帧信息创建帧结构体
Frame *read_frame(FILE *fp);

// 回放动画（从文件读取并展示）
void play_animation(const char *filename);

// 获取指定颜色的ANSI转义序列代码
char *get_color_code(const char *color_name);

// 在指定帧添加物体
void add_object_to_frame(Frame *frame, Object obj);

// 从指定帧删除指定物体（根据物体指针匹配）
void delete_object_from_frame(Frame *frame, Object *obj_to_delete);

#endif
