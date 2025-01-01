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
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *dummyHead = malloc(sizeof(struct ListNode));

    dummyHead->next = head;
    struct ListNode *cur = dummyHead;

    while (cur->next != NULL)
    {
        if(cur->next->val == val)
        {
            cur->next = cur->next->next;
        }
        else
        {
            cur = cur->next;
        }
    }

    return dummyHead->next;
}




