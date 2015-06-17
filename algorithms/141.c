#include <stdio.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head)
{
    struct ListNode *p1 = head;
    if ( p1 == NULL )
        return false;
    p1 = p1->next;
    struct ListNode *p2 = p1;
    if ( p2 == NULL )
        return false;
    p2 = p2->next;
    while ( p1 != p2 )
    {
        if ( p1 == NULL )
            return false;
        p1 = p1->next;
        if ( p2 == NULL )
            return false;
        p2 = p2->next;
        if ( p2 == NULL )
            return false;
        p2 = p2->next;
    }
    return true;
}

int main()
{
    return 0;
}
