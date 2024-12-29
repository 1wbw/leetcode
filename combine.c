#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int **result = NULL; //存放符合条件的集合
int temp_resultSize; //leetcode全局变量处理原因，全局变量初始化需放在函数内

// int *temp = NULL;

int *path = NULL;   //存放符合条件的单一结果
int pathlen;

void backtracking(int n, int k, int startIndex)
{
    // 终止条件
    if (pathlen == k)
    {
        int *temp = (int *)malloc(sizeof(int) * k);
        // 存放结果;
        for (int i = 0; i < k; i++)
        {
            temp[i] = path[i];
        }
        result[temp_resultSize++] = temp;

        return;
    }

    //for循环横向遍历树形结构
    for (int i = startIndex; i <= n - (k - pathlen) + 1;i++)
    {
        path[pathlen++] = i;
        //递归：树的纵向遍历
        backtracking(n , k, i + 1);
        //回溯
        pathlen--;
    }
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {
    result = (int **)malloc(sizeof(int *) * 200001);
    path = (int *)malloc(sizeof(int) * k);

    pathlen = 0;
    temp_resultSize = 0;

    backtracking(n, k, 1);

    *returnSize = temp_resultSize;
    *returnColumnSizes = (int *)malloc(sizeof(int) * temp_resultSize);

    for (int i = 0; i < temp_resultSize; i++)
    {
        (*returnColumnSizes)[i] = k;
    }

    return result;
}


int main()
{
    int n = 20;
    int k = 9;
    int returnSize = 0;
    int **Result = NULL;
    int *returnColumnSizes = NULL;

    Result = combine(n, k, &returnSize,&returnColumnSizes);

    printf("returnSize = %d\r\n", returnSize);

    return 0;
}

