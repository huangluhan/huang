#include "animation.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// 颜色代码映射表（可扩展更多颜色）
const char *color_map[][2] = {
    {"red", "\033[31m"},
    {"green", "\033[32m"},
    {"blue", "\033[34m"},
    {"yellow", "\033[33m"},
    {"magenta", "\033[35m"},
    {"cyan", "\033[36m"},
    {NULL, NULL}
};

// 初始化一个物体
Object init_object(int x, int y, char shape, char *color_code) {
    Object obj;
    obj.x = x;
    obj.y = y;
    obj.shape = shape;
    strcpy(obj.color_code, color_code);
    return obj;
}

// 初始化一帧画面
Frame *init_frame(int num_objects) {
    Frame *frame = (Frame *)malloc(sizeof(Frame));
    if (frame == NULL) {
        perror("Memory allocation failed for frame");
        return NULL;
    }
    frame->num_objects = num_objects;
    frame->objects = (Object *)malloc(num_objects * sizeof(Object));
    if (frame->objects == NULL) {
        perror("Memory allocation failed for objects in frame");
        free(frame);
        return NULL;
    }
    frame->next = NULL;
    return frame;
}

// 在终端指定位置输出彩色字符（简单模拟绘制物体）
void draw_object(Object obj) {
    printf("\033[%d;%dH%s%c%s", obj.y, obj.x, obj.color_code, obj.shape, RESET_COLOR);
    fflush(stdout);
}

// 绘制一帧画面（绘制该帧包含的所有物体）
void draw_frame(Frame *frame) {
    for (int i = 0; i < frame->num_objects; i++) {
        draw_object(frame->objects[i]);
    }
}

// 释放帧内存（包括帧内物体的内存）
void free_frame(Frame *frame) {
    if (frame == NULL) {
        return;
    }
    free(frame->objects);
    free(frame);
}

// 导出动画（简单以文本格式记录每一帧物体信息到文件）
void export_animation(Frame *head, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file for export");
        return;
    }
    Frame *current = head;
    while (current!= NULL) {
        fprintf(fp, "%d\n", current->num_objects);
        for (int i = 0; i < current->num_objects; i++) {
            fprintf(fp, "%d %d %c %s\n", current->objects[i].x, current->objects[i].y, current->objects[i].shape, current->objects[i].color_code);
        }
        current = current->next;
    }
    fclose(fp);
    printf("Animation exported successfully to %s.\n", filename);
}

// 从文件读取一帧信息创建帧结构体
Frame *read_frame(FILE *fp) {
    int num_objects;
    if (fscanf(fp, "%d", &num_objects)!= 1) {
        return NULL;
    }
    Frame *frame = init_frame(num_objects);
    if (frame == NULL) {
        return NULL;
    }
    for (int i = 0; i < num_objects; i++) {
        int x, y;
        char shape[2];
        char color_code[20];
        if (fscanf(fp, "%d %d %s %s", &x, &y, shape, color_code)!= 4) {
            free_frame(frame);
            return NULL;
        }
        frame->objects[i] = init_object(x, y, shape[0], color_code);
    }
    return frame;
}

// 回放动画（从文件读取并展示）
void play_animation(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file for playback");
        return;
    }
    Frame *current;
    while ((current = read_frame(fp))!= NULL) {
        draw_frame(current);
        usleep(100000);  // 简单模拟帧率，这里设置为每秒10帧左右，可调整
        system("clear");  // 清屏用于下一帧展示
        free_frame(current);
    }
    fclose(fp);
    printf("Animation playback completed.\n");
}

// 获取指定颜色的ANSI转义序列代码
char *get_color_code(const char *color_name) {
    for (int i = 0; color_map[i][0]!= NULL; i++) {
        if (strcmp(color_name, color_map[i][0]) == 0) {
            return (char *)color_map[i][1];
        }
    }
    return RESET_COLOR;  // 默认返回重置颜色代码，如果没找到对应颜色
}

// 在指定帧添加物体
void add_object_to_frame(Frame *frame, Object obj) {
    if (frame == NULL) {
        return;
    }
    Object *new_objects = (Object *)realloc(frame->objects, (frame->num_objects + 1) * sizeof(Object));
    if (new_objects == NULL) {
        perror("Memory reallocation failed for adding object to frame");
        return;
    }
    frame->objects = new_objects;
    frame->objects[frame->num_objects] = obj;
    frame->num_objects++;
}

// 从指定帧删除指定物体（根据物体指针匹配）
void delete_object_from_frame(Frame *frame, Object *obj_to_delete) {
    if (frame == NULL || obj_to_delete == NULL) {
        return;
    }
    int index = -1;
    for (int i = 0; i < frame->num_objects; i++) {
        if (&frame->objects[i] == obj_to_delete) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return;  // 没找到要删除的物体
    }
    for (int i = index; i < frame->num_objects - 1; i++) {
        frame->objects[i] = frame->objects[i + 1];
    }
    frame->num_objects--;
    Object *new_objects = (Object *)realloc(frame->objects, frame->num_objects * sizeof(Object));
    if (new_objects!= NULL) {
        frame->objects = new_objects;
    }
}
