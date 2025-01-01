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
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *dummyhead = malloc(sizeof(struct ListNode)); 
    int listsize = 0;

    dummyhead->next = head;
    struct ListNode *cur = dummyhead;

    // 遍历整个链表
    while (cur->next != NULL)
    {
        cur = cur->next;
        listsize++;
    }

    cur = dummyhead;

    for (int i = 0; i < listsize - n; i++)
    {
        cur = cur->next;
    }

    cur->next = cur->next->next;

    return dummyhead->next;
}


