#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    int arr[100] = {0};
    int arrlen = 0;
    struct ListNode *cur = NULL;    

    struct ListNode *dummyNode = malloc(sizeof(struct ListNode));
    struct ListNode *tempNode1 = malloc(sizeof(struct ListNode));
    struct ListNode *tempNode2 = malloc(sizeof(struct ListNode));
    dummyNode->next = head;
    cur = dummyNode;

    if (head == NULL)
    {
        return NULL;
    }
    

    while (cur->next != NULL)
    {
        arr[arrlen++] = (cur->next)->val;
        cur = cur->next;
    }

    dummyNode->next = head;
    cur = dummyNode;

    printf("len: %d\r\n", arrlen);

    if(arrlen == 1)
    {
        return dummyNode->next;
    }

    for (int i = 0; i < (arrlen/2); i++)
    {
        tempNode1 = cur->next;
        printf("cur->val: %d, i = %d\r\n", cur->val, i);
        printf("cur->next->val: %d, i = %d\r\n", cur->next->val, i);
        if(cur->next->next->next == NULL)
        {
            tempNode2 = NULL;
        }
        else
        {
            tempNode2 = cur->next->next->next;
        }
        cur->next = cur->next->next;
        cur->next->next = tempNode1;
        cur->next->next->next = tempNode2;

        cur = cur->next->next;
    }

    return dummyNode->next;
}





