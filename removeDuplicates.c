#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int removeDuplicates(int* nums, int numsSize) {

    int *result = malloc(sizeof(int) * numsSize);
    int resultSize = 0;

    // printf("numsSize = %d\r\n", numsSize);

    for (int i = 0; i < numsSize; i++)
    {
        if((i - 1 >= 0) && (nums[i] == nums[i - 1]))
        {
            continue;
        }
        else
        {
            result[resultSize++] = nums[i];
        }
    }
    
    // for(int i = 0;i < resultSize;i++)
    // {
    //     printf("result: %d\r\n", result[i]);
    // }

    // printf("resultSize = %d\r\n", resultSize);
    for(int i = 0;i < resultSize;i++)
    {
        nums[i] = result[i];
    }

    // for(int i = 0;i < resultSize;i++)
    // {
    //     printf("nums: %d\r\n", nums[i]);
    // }

    return resultSize;
}