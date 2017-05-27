#include <iostream>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        RandomListNode *p, *q;

        p = head;
        while (p) {
            q = p->next;
            p->next = new RandomListNode(p->label);
            p->next->next = q;
            p = q;
        }

        p = head;
        while (p) {
            if (p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }

        RandomListNode *copy = head->next;
        p = head->next = copy->next;
        q = copy;
        while (p) {
            q = q->next = p->next;
            p = p->next = p->next->next;
        }
        q->next = NULL;

        return copy;
    }
};

int main() {
    return 0;
}
