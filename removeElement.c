#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int removeElement(int* nums, int numsSize, int val) {
    int resultSize = 0;
    int *result = malloc(sizeof(int) * numsSize);

    for (int i = 0; i < numsSize; i++)
    {
        if(nums[i] != val)
        {
            result[resultSize++] = nums[i];
        }
        else
        {
            continue;
        }
    }

    for (int i = 0; i < resultSize; i++)
    {
        nums[i] = result[i];
    }

    return resultSize;
}