#include <iostream>
#include <vector>
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
    void reorderList(ListNode* head)
    {
        if ( head == NULL )
            return;
        vector<ListNode *> stack;
        while ( head )
        {
            stack.push_back(head);
            head = head->next;
        }
        int len = stack.size();
        for ( int i = 0; i < len/2; ++i )
        {
            stack[i]->next = stack[len-1-i];
            stack[len-1-i]->next = stack[i+1];
        }
        stack[len/2]->next = NULL;
        return;
    }
};

int main()
{
    return 0;
}
