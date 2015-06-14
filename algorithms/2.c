#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *ans = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p = ans;
    int carry = 0;
    (*ans).val = ((*l1).val+(*l2).val+carry)%10;
    (*ans).next = NULL;
    carry = ((*l1).val+(*l2).val+carry)/10;
    while ( (*l1).next != NULL && (*l2).next != NULL )
    {
        l1 = (*l1).next;
        l2 = (*l2).next;
        (*p).next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p = (*p).next;
        (*p).val = ((*l1).val+(*l2).val+carry)%10;
        (*p).next = NULL;
        carry = ((*l1).val+(*l2).val+carry)/10;
    }
    while ( (*l1).next != NULL )
    {
        l1 = (*l1).next;
        (*p).next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p = (*p).next;
        (*p).val = ((*l1).val+carry)%10;
        (*p).next = NULL;
        carry = ((*l1).val+carry)/10;
    }
    while ( (*l2).next != NULL )
    {
        l2 = (*l2).next;
        (*p).next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p = (*p).next;
        (*p).val = ((*l2).val+carry)%10;
        (*p).next = NULL;
        carry = ((*l2).val+carry)/10;
    }
    if ( carry )
    {
        (*p).next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p = (*p).next;
        (*p).val = carry;
        (*p).next = NULL;
    }
    return ans;
}

int main()
{
    return 0;
}
