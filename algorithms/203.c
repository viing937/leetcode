#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode *p, *q;
    while ( head && head->val == val )
    {
        p = head->next;
        free(head);
        head = p;
    }
    if ( !head )
        return head;
    p = head, q = head->next;
    while ( q )
    {
        if ( q->val == val )
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
        else
        {
            p = p->next;
            q = p->next;
        }
    }
    return head;
}

int main()
{
    return 0;
}
