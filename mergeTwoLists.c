#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

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
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    int arr[100] = {0};
    int arrlen = 0;
    struct ListNode *cur = NULL;
    int i = 0;

    if(list1 == NULL && list2 == NULL)
    {
        return NULL;
    }

    struct ListNode *dummyNode = malloc(sizeof(struct ListNode));
    dummyNode->next = list1;
    cur = dummyNode;

    //遍历链表1中的元素
    while (cur->next != NULL)
    {
        arr[arrlen++] = (cur->next)->val;
        cur = cur->next;
    }

    dummyNode->next = list2;
    cur = dummyNode;

    //遍历链表2中的元素
    while (cur->next != NULL)
    {
        arr[arrlen++] = (cur->next)->val;
        cur = cur->next;
    }  

    qsort(arr, arrlen, sizeof(int), compare);
    
    struct ListNode *resulthead = malloc(sizeof(struct ListNode));

    cur = resulthead;

    for (i = 0; i < arrlen - 1; i++)
    {
        struct ListNode *tmp = malloc(sizeof(struct ListNode));

        cur->val = arr[i];
        cur->next = tmp;

        cur = cur->next;
    }
    cur->val = arr[i];
    cur->next = NULL;
    
    return resulthead;
}



