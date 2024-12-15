#include <stdio.h>
#include <stdlib.h>

// 定义链表节点的结构体
typedef struct list_item {
    int data; 
    struct list_item *next;
} list_item;

// 非递归版本的链表空间释放函数
void erase_list(list_item *head) {
    list_item *current = head; // 指向当前节点
    list_item *next_node;      // 指向下一个节点

    // 遍历链表直到到达末尾
    while (current != NULL) {
        next_node = current->next; // 保存下一个节点的地址
        free(current);             // 释放当前节点的内存
        current = next_node;       // 移动到下一个节点
    }
}

int main() {
    list_item *head = malloc(sizeof(list_item)); // 头节点
    head->data = 1;
    head->next = malloc(sizeof(list_item));     // 第二个节点
    head->next->data = 2;
    head->next->next = NULL;                    // 链表结束

    // 释放链表
    erase_list(head);

    return 0;
}
