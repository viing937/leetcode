#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head)
{
    if ( !head || !head->next )
        return head;
    struct ListNode *p, *q, *t;
    p = head;
    q = head->next;
    t = q->next;
    q->next = p;
    p->next = swapPairs(t);
    return q;
}

int main()
{
    return 0;
}
