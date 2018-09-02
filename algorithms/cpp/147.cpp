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
    ListNode* insertionSortList(ListNode* head)
    {
        if ( head == NULL || head->next == NULL )
            return head;
        ListNode *p = head->next;
        head->next = NULL;
        while ( p )
        {
            ListNode *pre = NULL, *cur = head;
            while ( cur && p->val > cur->val )
            {
                pre = cur;
                cur = cur->next;
            }
            ListNode *node = p;
            p = p->next;
            node->next = cur;
            if ( pre )
                pre->next = node;
            else
                head = node;
        }
        return head;
    }
};

int main()
{
    return 0;
}
