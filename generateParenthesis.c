#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char pairs(char a) {
    if (a == '}') return '{';
    if (a == ']') return '[';
    if (a == ')') return '(';
    return 0;
}

bool isValid(char* s) {
    int n = strlen(s);
    if (n % 2 == 1) {
        return false;
    }
    int stk[n + 1], top = 0;
    for (int i = 0; i < n; i++) {
        char ch = pairs(s[i]);
        if (ch) {
            if (top == 0 || stk[top - 1] != ch) {
                return false;
            }
            top--;
        } else {
            stk[top++] = s[i];
        }
    }
    return top == 0;
}


// 回溯法（暴力）
#if 1
char **result;
int temp_resultsize;

char *path;
int pathlen;

const char arr[2] = {'(', ')'};

void backtracking(int n)
{
    // 终止条件
    if(pathlen == 2*n)
    {
        if((path[0] == ')') || (path[2*n - 1] == '('))
        {
            return;
        }

        char *tmp = malloc(sizeof(char) * (2*n) + 1);
        for(int i = 0;i < 2*n;i++)
        {
            tmp[i] = path[i];
        }
        tmp[2*n] = '\0';

        if(isValid(tmp))
        {
            result[temp_resultsize++] = tmp;
        }
        else
        {
            free(tmp);
        }

        return;
    }

    for (int i = 0; i < 2; i++)
    {
        path[pathlen++] = arr[i];

        backtracking(n);

        pathlen--;
    }
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    temp_resultsize = 0;
    pathlen = 0;

    path = malloc(sizeof(char) * (2*n));
    result = (char **)malloc(sizeof(char *) * 10000);

    backtracking(n);

    *returnSize = temp_resultsize;

    return result;
}
#endif


// 暴力法（未实现）
#if 0
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    arr = malloc(sizeof(char) * (2 * n));

    // 初始化arr数组
    for(int i = 0;i < 2 * n;i++)
    {
        if(i <= (2*n - 1))
        {
            arr[i] = '(';
        }
        else
        {
            arr[i] = ')';
        }
    }

    for (int i = 0; i < 2 * n; i++)
    {
        if()
        {

        }
    }
}
#endif

int main()
{
    int n = 3;
    int returnSize = 0;
    char **Result = NULL;

    Result = generateParenthesis(n, &returnSize);

    printf("returnSize = %d\r\n", returnSize);

    return 0;
}


