#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode *p, *q, *t;
    q = head;
    while ( n-- )
        q = q->next;
    if ( !q )
    {
        t = head;
        head = head->next;
        free(t);
        return head;
    }
    else
    {
        p = head;
        q = q->next;
    }
    while ( q )
    {
        p = p->next;
        q = q->next;
    }
    t = p->next;
    p->next = p->next->next;
    free(t);
    return head;
}

int main()
{
    return 0;
}
