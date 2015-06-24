#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *result = p;
    while ( l1 && l2 )
    {
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p = p->next;
        if ( l1->val < l2->val )
        {
            p->val = l1->val;
            l1 = l1->next;
        }
        else
        {
            p->val = l2->val;
            l2 = l2->next;
        }
    }
    while ( l1 )
    {
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = l1->val;
        l1 = l1->next;
    }
    while ( l2 )
    {
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p = p->next;
        p->val = l2->val;
        l2 = l2->next;
    }
    p->next = NULL;
    p = result;
    result = result->next;
    free(p);
    return result;
}

int main()
{
    return 0;
}
