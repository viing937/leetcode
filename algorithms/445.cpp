#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode *makeNode(int a, int b, int &carry) {
        ListNode *node = new ListNode(a + b + carry);
        carry = node->val / 10;
        node->val %= 10;
        return node;
    }
    ListNode *insertNode(ListNode *head, ListNode *node) {
        node->next = head;
        return node;
    }
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        stack<int> num1, num2;
        for (ListNode *p = l1; p != NULL; p = p->next)
            num1.push(p->val);
        for (ListNode *p = l2; p != NULL; p = p->next)
            num2.push(p->val);
        ListNode *result = NULL;
        int carry = 0;
        while (!num1.empty() && !num2.empty()) {
            result = insertNode(result, makeNode(num1.top(), num2.top(), carry));
            num1.pop(); num2.pop();
        }
        while (!num1.empty()) {
            result = insertNode(result, makeNode(num1.top(), 0, carry));
            num1.pop();
        }
        while (!num2.empty()) {
            result = insertNode(result, makeNode(0, num2.top(), carry));
            num2.pop();
        }
        if (carry)
            result = insertNode(result, makeNode(0, 0, carry));
        return result;
    }
};

int main() {
    return 0;
}
