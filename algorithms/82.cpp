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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode *newhead = new ListNode(0), *p = newhead;
        while ( head )
        {
            if ( head->next == NULL || head->val != head->next->val )
            {
                p = p->next = head;
                head = head->next;
            }
            else
            {
                int val = head->val;
                while ( head && head->val == val )
                {
                    ListNode *tmp = head;
                    head = head->next;
                    delete(tmp);
                }
            }
        }
        p->next = NULL;
        p = newhead;
        newhead = newhead->next;
        delete(p);
        return newhead;
    }
};

int main()
{
    return 0;
}
