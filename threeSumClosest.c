#include <stdio.h>
#include <math.h>

/* 快速排序*/ 

// 比较函数，用于升序排列
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int minsum = nums[0] + nums[1] + nums[2];
    int *pb = NULL;
    int *pc = NULL;

    // 校验长度和数组
    if((nums == NULL) || (numsSize < 3))
    {
        return -1;
    }

    // 调用 qsort 函数进行排序
    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i < numsSize; i++)
    {
        printf("nums: %d\r\n",nums[i]);
    }
    
    // 计算最小的和
    for (int i = 0; i < numsSize - 2; i++)
    {
        pb = &nums[i + 1];
        pc = &nums[numsSize - 1];

        while (pc != pb)
        {
            if ((nums[i] + *pb + *pc) == target)
            {
                return target;
            }
            
            // a + b + c >= target c指针左移
            if(nums[i] + *pb + *pc > target)
            {
                // printf("abs(minsum) - abs(target) : %d\r\n",abs(minsum) - abs(target));
                
                if (abs((minsum) - (target)) > abs(nums[i] + *pb + *pc - target))
                {
                    minsum = (nums[i] + *pb + *pc);
                }

                // minsum = ((abs(minsum) - abs(target)) > abs(((nums[i] + *pb + *pc) - abs(target)))  ? (nums[i] + *pb + *pc) : minsum);
                pc--;
            }
            else
            {
                if (abs((minsum) - (target)) > abs(nums[i] + *pb + *pc - target))
                {
                    minsum = (nums[i] + *pb + *pc);
                }

                // minsum = ((abs(minsum) - abs(target)) > abs(((nums[i] + *pb + *pc) - abs(target)))  ? (nums[i] + *pb + *pc) : minsum);
                pb++;
            }
        }
    }

    return minsum;
}


int main()
{
    int nums[9] = {1, 1, 1, 5, 5, 5, 5, 5, 5};
    int numssize = sizeof(nums)/sizeof(nums[0]);

    int target = 14;

    int sum = threeSumClosest(nums, numssize, target);

    printf("sum = %d\r\n", sum);

    return 0;
}