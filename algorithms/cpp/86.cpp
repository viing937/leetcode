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
    ListNode* partition(ListNode* head, int x)
    {
        if ( head == NULL )
            return head;
        ListNode *s1 = new ListNode(0);
        ListNode *s2 = new ListNode(0);
        ListNode *e1 = s1, *e2 = s2;
        while ( head )
        {
            if ( head->val < x )
                e1 = e1->next = head;
            else
                e2 = e2->next = head;
            head = head->next;
        }
        e2->next = NULL;
        e1->next = s2->next;
        ListNode *ret = s1->next;
        delete s1; delete s2;
        return ret;
    }
};

int main()
{
    return 0;
}
