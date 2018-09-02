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
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        ListNode *prev = NULL, *current = head;
        n = n-m+1;
        while ( --m && current )
        {
            prev = current;
            current = current->next;
        }
        ListNode *s = prev;
        ListNode *s2 = current;
        while ( n && current )
        {
            n -= 1;
            ListNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        if ( s )
            s->next = prev;
        if ( s2 )
            s2->next = current;
        return s ? head : prev;
    }
};

int main()
{
    return 0;
}
