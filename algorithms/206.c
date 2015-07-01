#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head)
{
    if ( !head )
        return head;
    struct ListNode *p, *q;
    p = head->next;
    head->next = NULL;
    while ( p )
    {
        q = p;
        p = p->next;
        q->next = head;
        head = q;
    }
    return head;
}

int main()
{
    return 0;
}
