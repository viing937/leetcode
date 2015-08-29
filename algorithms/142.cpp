#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if ( head == NULL || head->next == NULL )
            return NULL;
        ListNode *slow = head->next, *fast = slow->next;
        while ( slow != fast && fast && fast->next )
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if ( fast != slow )
            return NULL;
        fast = head;
        while ( slow != fast )
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main()
{
    return 0;
}
