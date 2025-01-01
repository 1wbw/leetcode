#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// 回溯法（但有部分测试用例超出了时间限制）
#if 0
int **result = NULL;
int temp_resultsize;

int *path = NULL;
int pathlen;

int samenum;

int *sort1;
int *sort2;


// 比较函数，用于升序排列
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void backtracking(int *nums, int n, int startindex,int target)
{
    //终止条件
    if (pathlen == 4)
    {
        //本题虽然数据类型是 int，但多个 int 相加可能会溢出，需要用 long 保存相加的结果。
        if((long)path[0] + (long)path[1] + (long)path[2] + (long)path[3] == target)
        {
            //去重
            for (int i = 0; i < temp_resultsize; i++)
            {
                memcpy(sort1, result[i], 16);
                memcpy(sort2, path, 16);

                // 调用 qsort 函数进行排序
                qsort(sort1, 4, sizeof(int), compare);
                qsort(sort2, 4, sizeof(int), compare);

                for (int j = 0; j < 4; j++)
                {
                    if(sort1[j] == sort2[j])
                    {
                        samenum++;
                    }
                }

                if(samenum == 4)
                {
                    samenum = 0;
                    return;
                }
                samenum = 0;
            }

            int *tmp = malloc(sizeof(int) * 4);
            for (int i = 0; i < 4; i++)
            {
                tmp[i] = path[i];
            }

            result[temp_resultsize++] = tmp;
        }
        return;
    }

    for (int i = startindex; i <= n - (4 - pathlen); i++)
    {
        path[pathlen++] = nums[i];
        backtracking(nums, n, i + 1,target);
        pathlen--;
    }
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    
    result = malloc(sizeof(int *) * 20000);
    path = malloc(sizeof(int) * 4);
    sort1 = malloc(sizeof(int) * 4);
    sort2 = malloc(sizeof(int) * 4);

    temp_resultsize = 0;
    pathlen = 0;
    samenum = 0;

    qsort(nums, numsSize, sizeof(int), compare);
    backtracking(nums,numsSize,0,target);

    *returnSize = temp_resultsize;

    *returnColumnSizes = malloc(sizeof(int) * temp_resultsize);
    for (int i = 0; i < temp_resultsize; i++)
    {
        (*returnColumnSizes)[i] = 4;
    }
    
    return result;
}
#endif
int **result = NULL;
int temp_resultsize;

int samenum;

// 比较函数，用于升序排列
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    
    int *left = NULL;
    int *right = NULL;

    result = malloc(sizeof(int *) * 10000);
    temp_resultsize = 0;
    samenum = 0;
    //先排序
    qsort(nums, numsSize, sizeof(int), compare);

    for(int i = 0;i < (numsSize - 3);i++)
    {
        // 去重
        if((i > 0) && (nums[i] == nums[i - 1]))
        {
            continue;
        }

        for (int j = i + 1; j < numsSize - 2; j++)
        {
            //去重
            if((j > i + 1) && (nums[j] == nums[j - 1]))
            {
                continue;
            }

            left = &nums[j + 1];
            right = &nums[numsSize - 1];

            while (left < right)
            {
                if(((long)nums[i] + (long)nums[j] + (long)(*left) + (long)(*right)) == target)
                {
                    int *tmp = malloc(sizeof(int) * 4);
                    tmp[0] = nums[i];
                    tmp[1] = nums[j];
                    tmp[2] = (*left);
                    tmp[3] = (*right);
      
                    result[temp_resultsize++] = tmp;

                    while((left < right) && (*left) == *(left + 1))
                    {
                        left++;
                    }
                    left++;

                    while((left < right) &&(*right) == *(right - 1))
                    {
                        right--;
                    }

                    right--;
                }
                else if(((long)nums[i] + (long)nums[j] + (long)(*left) + (long)(*right)) > target)
                {
                    right--;
                }
                else if(((long)nums[i] + (long)nums[j] + (long)(*left) + (long)(*right)) < target)
                {
                    left++;
                }

            }
        }        
    }

    *returnSize = temp_resultsize;
    *returnColumnSizes = malloc(sizeof(int) * temp_resultsize);
    for (int i = 0; i < temp_resultsize; i++)
    {
        (*returnColumnSizes)[i] = 4;
    }

    return result;
}



int main()
{
    // int nums[8] = {-3,-2,-1,0,0,1,2,3};
    int nums[5] = {2,2,2,2,2};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int target = 8;
    int returnSize = 0;
    int **Result = NULL;
    int *returnColumnSizes = NULL;

    Result = fourSum(nums, numsSize, target, &returnSize, &returnColumnSizes);

    printf("returnSize = %d\r\n", returnSize);

    return 0;
}

// 1 2 2 2 2 2
// 1 2 3 4 5 6 7 (n-2 )


