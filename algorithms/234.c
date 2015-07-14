#include <stdio.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *reverse(struct ListNode *head)
{
    if ( head == NULL )
        return head;
    struct ListNode *newHead = NULL, *tmp = NULL;
    while ( head )
    {
        tmp = head;
        head = head->next;
        tmp->next = newHead;
        newHead = tmp;
    }
    return newHead;
}

bool isPalindrome(struct ListNode* head)
{
    if ( head == NULL )
        return true;
    struct ListNode *slow = head, *fast = head;
    while ( fast->next != NULL && fast->next->next != NULL )
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverse(slow->next);
    slow = slow->next;
    while ( slow != NULL )
    {
        if ( head->val != slow->val )
            return false;
        head = head->next;
        slow = slow->next;
    }
    return true;
}

int main()
{
    return 0;
}
