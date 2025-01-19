#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode* pre = NULL;
    struct ListNode* temp = NULL;

    while(cur != NULL)
    {
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }

    return pre;
}



// 反转链表

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *dummyNode = malloc(sizeof(struct ListNode));
    struct ListNode *pre = NULL;
    struct ListNode *end = NULL;
    struct ListNode *start = NULL;
    struct ListNode *next = NULL; 

    dummyNode->next = head;

    if (head == NULL)
    {
        return NULL;
    }
    
    if(1 == k)
    {
        return dummyNode->next;
    }

    end = dummyNode;
    pre = dummyNode;

    while (end->next != NULL)
    {
        for(int i = 0;i < k && end != NULL;i++)
        {   
            end = end->next;
        }  
        if(end == NULL)
        {
            break;
        }

        start = pre->next;
        next = end->next;
        
        //关键
        end->next = NULL;

        pre->next = reverseList(start);
        start->next = next;

        pre = start;
        end = pre;
    }

    return dummyNode->next;
}

