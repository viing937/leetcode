#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode *head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode *head) {
        this->head = head;
    }
    /** Returns a random node's value. */
    int getRandom() {
        int result = head->val, cnt = 1;
        ListNode *node = head->next;
        while (node) {
            cnt += 1;
            if (rand() % cnt == 0)
                result = node->val;
            node = node->next;
        }
        return result;
    }
};

int main() {
    return 0;
}
