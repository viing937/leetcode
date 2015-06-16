#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    if ( !headA || !headB )
        return NULL;
    struct ListNode *p1, *p2;
    struct ListNode *tailA = headA, *tailB = headB;
    while ( (*tailA).next != NULL )
        tailA = (*tailA).next;
    while ( (*tailB).next != NULL )
        tailB = (*tailB).next;
    if ( tailA != tailB )
        return NULL;
    (*tailA).next = headA;
    p1 = (*headB).next;
    p2 = (*p1).next;
    while ( p1 != p2 )
    {
        p1 = (*p1).next;
        p2 = (*p2).next;
        p2 = (*p2).next;
    }
    p2 = headB;
    while ( p1 != p2 )
    {
        p1 = (*p1).next;
        p2 = (*p2).next;
    }
    (*tailA).next = NULL;
    return p1;
}

int main()
{
    return 0;
}
