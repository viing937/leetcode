#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if ( head == NULL || head->next == NULL )
        return head;
    struct ListNode *p, *q;
    p = head;
    q = p->next;
    while ( q != NULL )
    {
        if ( p->val == q->val )
        {
            q = q->next;
            free(p->next);
            p->next = q;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
    return head;
}

int main()
{
    return 0;
}
