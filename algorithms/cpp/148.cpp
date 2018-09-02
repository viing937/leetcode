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
private:
    ListNode *sortList(ListNode *head, int num)
    {
        if ( num <= 1 )
            return head;
        ListNode *l1 = head, *l2 = head;
        ListNode *tail;
        for ( int i = 0; i < num/2-1; ++i )
            l2 = l2->next;
        tail = l2;
        l2 = l2->next;
        tail->next = NULL;
        l1 = sortList(l1, num/2), l2 = sortList(l2, num-num/2);
        head = new ListNode(0), tail = head;
        while ( l1 && l2 )
        {
            if ( l1->val <= l2->val )
            {
                tail = tail->next = l1;
                l1 = l1->next;
                tail->next = NULL;
            }
            else
            {
                tail = tail->next = l2;
                l2 = l2->next;
                tail->next = NULL;
            }
        }
        while ( l1 )
        {
            tail = tail->next = l1;
            l1 = l1->next;
            tail->next = NULL;
        }
        while ( l2 )
        {
            tail = tail->next = l2;
            l2 = l2->next;
            tail->next = NULL;
        }
        tail = head;
        head = head->next;
        delete(tail);
        return head;
    }
public:
    ListNode* sortList(ListNode* head)
    {
        ListNode *p = head;
        int cnt = 0;
        while ( p )
        {
            cnt += 1;
            p = p->next;
        }
        return sortList(head, cnt);
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    Solution solution;
    solution.sortList(head);
    delete(head);
    return 0;
}
