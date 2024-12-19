#include <stdio.h>
#include <string.h>
#define length 5


// 打印字符图案的函数
void print(char *input) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        switch (input[i]) {
        case 'A':
            printf("  *****\n");
            printf(" *     \n");
            printf("*       \n");
            printf("*       \n");
            printf("*       \n");
            printf(" *     \n");
            printf("  *****\n");
            break;
        case 'B':
            printf("*******\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("*******\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("*******\n");
            break;
        case 'C':
            printf(" ******\n");
            printf("*      \n");
            printf("*      \n");
            printf("*      \n");
            printf("*      \n");
            printf("*      \n");
            printf(" ******\n");
            break;
        case 'D':
            printf("*******\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("*******\n");
            break;
        case 'E':
            printf("*******\n");
            printf("*      \n");
            printf("*      \n");
            printf("******\n");
            printf("*      \n");
            printf("*      \n");
            printf("*******\n");
            break;
        case 'F':
            printf("*******\n");
            printf("*      \n");
            printf("*      \n");
            printf("******\n");
            printf("*      \n");
            printf("*      \n");
            printf("*      \n");
            break;
        case 'G':
            printf(" ******\n");
            printf("*      \n");
            printf("*      \n");
            printf("*  ****\n");
            printf("*     *\n");
            printf("*     *\n");
            printf(" ******\n");
            break;
        case 'H':
            printf("*     *\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("*******\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("*     *\n");
            break;
        case 'I':
            printf("   ***   \n");
            printf("     *   \n");
            printf("     *   \n");
            printf("     *   \n");
            printf("     *   \n");
            printf("     *   \n");
            printf("   ***   \n");
            break;
        case 'J':
            printf("    *** \n");
            printf("      * \n");
            printf("      * \n");
            printf("      * \n");
            printf("*     * \n");
            printf("*     * \n");
            printf(" ****** \n");
            break;
        case 'K':
            printf("*    * \n");
            printf("*   *  \n");
            printf("*  *   \n");
            printf("***    \n");
            printf("*  *   \n");
            printf("*   *  \n");
            printf("*    * \n");
            break;
        case 'L':
            printf("*      \n");
            printf("*      \n");
            printf("*      \n");
            printf("*      \n");
            printf("*      \n");
            printf("*      \n");
            printf("*******\n");
            break;
        case 'M':
            printf("*     *\n");
            printf("**   **\n");
            printf("* * * *\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("*     *\n");
            break;
        case 'N':
            printf("*     *\n");
            printf("**    *\n");
            printf("* *   *\n");
            printf("*  *  *\n");
            printf("*   * *\n");
            printf("*    **\n");
            printf("*     *\n");
            break;
        case 'O':
            printf(" ******\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("*     *\n");
            printf(" ******\n");
            break;
        case 'P':
            printf("*******\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("******\n");
            printf("*      \n");
            printf("*      \n");
            printf("*      \n");
            break;
        case 'Q':
            printf(" ******\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("*  ** *\n");
            printf(" ******\n");
            break;
        case 'R':
            printf("*******\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("******\n");
            printf("*  *   \n");
            printf("*   *  \n");
            printf("*    *\n");
            break;
        case 'S':
            printf(" ******\n");
            printf("*      \n");
            printf("*  ****\n");
            printf("******\n");
            printf("*  ****\n");
            printf("*      \n");
            printf(" ******\n");
            break;
        case 'T':
            printf("*******\n");
            printf("   *    \n");
            printf("   *    \n");
            printf("   *    \n");
            printf("   *    \n");
            printf("   *    \n");
            printf("   *    \n");
            break;
        case 'U':
            printf("*     *\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("*     *\n");
            printf(" ******\n");
            break;
        case 'V':
            printf("*     *\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("  ***  \n");
            break;
        case 'W':
            printf("*     *\n");
            printf("*     *\n");
            printf("*     *\n");
            printf("* * * *\n");
            printf("**   **\n");
            printf("*     *\n");
            printf("*     *\n");
            break;
        case 'X':
            printf("*     *\n");
            printf(" *   * \n");
            printf("  * *  \n");
            printf("   *   \n");
            printf("  * *  \n");
            printf(" *   * \n");
            printf("*     *\n");
            break;
        case 'Y':
            printf("*     *\n");
            printf(" *   * \n");
            printf("  * *  \n");
            printf("   *   \n");
            printf("   *   \n");
            printf("   *   \n");
            printf("   *   \n");
            break;
        case 'Z':
            printf("*******\n");
            printf("     * \n");
            printf("    *  \n");
            printf("   *   \n");
            printf("  *    \n");
            printf(" *     \n");
            printf("*******\n");
            break;
        default:
            printf("不支持的字符\n");
            break;
        }
        if (i < len - 1) {
            printf("\n");
        }
    }
}

int main() {
    char input[length];
    printf("请输入少于5个字符：");
    scanf("%s", input);

    print(input);

    return 0;
}
