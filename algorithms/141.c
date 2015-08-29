#include <stdio.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head)
{
    if ( head == NULL || head->next == NULL )
        return false;
    struct ListNode *slow = head->next, *fast = slow->next;
    while ( slow != fast && fast && fast->next )
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow == fast;
}

int main()
{
    return 0;
}
