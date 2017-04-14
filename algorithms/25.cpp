#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head) return head;

        ListNode *p = head, *q = head;
        int cnt = 0;

        while (p && cnt < k) {
            p = p->next;
            cnt += 1;
        }

        if (cnt < k) return head;

        q = q->next;
        head->next = reverseKGroup(p, k);
        while (--cnt && q) {
            p = q;
            q = q->next;

            p->next = head;
            head = p;
        }

        return head;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);

    Solution solution;
    solution.reverseKGroup(head, 2);
    return 0;
}
