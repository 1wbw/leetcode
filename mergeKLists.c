#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


struct ListNode {
  int val;
  struct ListNode *next;
};

// 比较函数，用于升序排列
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    
    struct ListNode *result = NULL;
    int resultSize = 0;

    struct ListNode *dummyNode = NULL;
    struct ListNode *cur = NULL;

    int *arr = NULL;
    int i = 0;

    if (lists == NULL)
    {
        return NULL;
    }
    

    arr = malloc(sizeof(int) * 10000);
    dummyNode = malloc(sizeof(struct ListNode));

    // 静态数组：可以直接使用 sizeof 计算整个数组的字节数。
    // 动态数组（指针）：不能用 sizeof 来获取分配的内存大小，因为 sizeof 只会返回指针本身的大小。应该记录分配的元素数量，并根据这个数量和每个元素的大小来计算总字节数。
    // memset(arr,0,sizeof(arr)/sizeof(arr[0]));
    memset(arr,0,sizeof(int) * 10000);

    for (int i = 0; i < listsSize; i++)
    {
        dummyNode->next = lists[i];
        cur = dummyNode;

        while (cur->next != NULL)
        {
            arr[resultSize++] = (cur->next)->val;
            cur = cur->next;
        }
    }

    if(resultSize == 0)
    {
        return NULL;
    }

    qsort(arr, resultSize, sizeof(int), compare);

    printf("resultSize = %d\r\n", resultSize);
    for(int i = 0;i < resultSize;i++)
    {
        printf("arr: %d\r\n",arr[i]);
    }

    result = malloc(sizeof(struct ListNode));

    dummyNode->next = result;
    cur = dummyNode;

    for (i = 0; i < resultSize - 1; i++)
    {
        struct ListNode* tempNode = malloc(sizeof(struct ListNode));
        (cur->next)->val = arr[i];
        (cur->next)->next = tempNode;
        cur = cur->next;
    }
    cur->next->val = arr[resultSize - 1];

    // 注意：此处需要手动将地址清为NULL
    cur->next->next = NULL;

    // printf("cur->next->val: %d\r\n", cur->next->val);
    // printf("result->val = %d\r\n", result->val);
    // printf("result->val = %d\r\n", result->next->val);
    // printf("result->val = %d\r\n", result->next->next->val);
    // printf("result->val = %d\r\n", result->next->next->next->val);
    // printf("result->val = %d\r\n", result->next->next->next->next->val);
    // printf("result->val = %d\r\n", result->next->next->next->next->next->val);
    // printf("result->val = %d\r\n", result->next->next->next->next->next->next->val);
    // printf("result->val = %d\r\n", result->next->next->next->next->next->next->next->val);
    // printf("result end = %p\r\n", result->next->next->next->next->next->next->next->next);
    
    return result;
}





