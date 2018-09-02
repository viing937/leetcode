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
    ListNode* oddEvenList(ListNode* head)
    {
        if ( !head )
            return head;
        ListNode *even = NULL, *tail = NULL;
        ListNode *curr = head;
        int cnt = 0;
        while ( curr->next )
        {
            cnt += 1;
            if ( cnt%2 )
            {
                if ( !even )
                    even = tail = curr->next;
                else
                    tail = tail->next = curr->next;
                curr->next = curr->next->next;
            }
            else
                curr = curr->next;
        }
        if ( tail )
            tail->next = NULL;
        curr->next = even;
        return head;
    }
};

int main()
{
    return 0;
}
