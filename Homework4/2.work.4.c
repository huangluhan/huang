#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 100
#define MAX_LENGTH 100

// 拆分字符串为单词并统计
void countWords(char *lines[], int numLines) {
    int wordCount = 0;
    char *words[MAX_LINES * MAX_LENGTH];
    int lineWordCount[MAX_LINES][MAX_LINES * MAX_LENGTH];
    int totalWordCount[MAX_LINES * MAX_LENGTH];

    // 初始化统计数组
    for (int i = 0; i < MAX_LINES * MAX_LENGTH; i++) {
        totalWordCount[i] = 0;
        for (int j = 0; j < MAX_LINES; j++) {
            lineWordCount[j][i] = 0;
        }
    }

    // 处理每一行输入
    for (int i = 0; i < numLines; i++) {
        char *line = lines[i];
        char *token = strtok(line, " ");
        while (token!= NULL) {
            int found = 0;
            for (int j = 0; j < wordCount; j++) {
                if (strcmp(words[j], token) == 0) {
                    totalWordCount[j]++;
                    lineWordCount[i][j]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                words[wordCount] = strdup(token);
                totalWordCount[wordCount]++;
                lineWordCount[i][wordCount]++;
                wordCount++;
            }
            token = strtok(NULL, " ");
        }
    }

    // 输出结果
    for (int i = 0; i < wordCount; i++) {
        printf("单词: %s\n", words[i]);
        printf("总行数中出现次数: %d\n", totalWordCount[i]);
        for (int j = 0; j < numLines; j++) {
            if (lineWordCount[j][i] > 0) {
                printf("在第 %d 行出现次数: %d\n", j + 1, lineWordCount[j][i]);
            }
        }
        printf("\n");
    }
}

int main() {
    char *inputLines[MAX_LINES];
    int lineCount = 0;
    char buffer[MAX_LENGTH];

    printf("请输入英文字符串（输入END结束）:\n");
    while (1) {
        fgets(buffer, MAX_LENGTH, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        if (strcmp(buffer, "END") == 0) {
            break;
        }
        inputLines[lineCount] = strdup(buffer);
        lineCount++;
        if (lineCount >= MAX_LINES) {
            break;
        }
    }

    countWords(inputLines, lineCount);

    // 释放内存
    for (int i = 0; i < lineCount; i++) {
        free(inputLines[i]);
    }

    return 0;
}
