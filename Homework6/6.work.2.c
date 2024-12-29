#include "animation.h"

int main() {
    // 示例创建一个简单的两帧动画，每帧包含两个物体
    Frame *frame1 = init_frame(2);
    if (frame1 == NULL) {
        return 1;
    }
    char *red_color = get_color_code("red");
    char *green_color = get_color_code("green");
    frame1->objects[0] = init_object(10, 5, 'O', red_color);
    frame1->objects[1] = init_object(20, 8, '*', green_color);

    Frame *frame2 = init_frame(2);
    if (frame2 == NULL) {
        free_frame(frame1);
        return 1;
    }
    char *blue_color = get_color_code("blue");
    char *yellow_color = get_color_code("yellow");
    frame2->objects[0] = init_object(12, 6, 'O', blue_color);
    frame2->objects[1] = init_object(22, 9, '*', yellow_color);

    frame1->next = frame2;

    // 导出动画到文件
    export_animation(frame1, "animation.txt");

    // 回放动画
    play_animation("animation.txt");

    // 示例：在第一帧添加一个新物体
    Object new_obj = init_object(15, 7, '#', get_color_code("magenta"));
    add_object_to_frame(frame1, new_obj);

    // 示例：删除第二帧中的一个物体（这里删除第二个物体）
    delete_object_from_frame(frame2, &frame2->objects[1]);

    // 再次导出更新后的动画
    export_animation(frame1, "updated_animation.txt");

    // 释放内存
    Frame *current = frame1;
    Frame *next;
    while (current!= NULL) {
        next = current->next;
        free_frame(current);
        current = next;
    }

    return 0;
}
