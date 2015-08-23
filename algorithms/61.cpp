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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if ( head == NULL || head->next == NULL || k == 0 )
            return head;
        int len = 1;
        ListNode *tail = head;
        while ( tail->next )
        {
            tail = tail->next;
            len += 1;
        }
        k = len-k%len;
        if ( k == 0 )
            return head;
        ListNode *mid = head;
        while ( --k )
            mid = mid->next;
        tail->next = head;
        head = mid->next;
        mid->next = NULL;
        return head;
    }
};

int main()
{
    return 0;
}
