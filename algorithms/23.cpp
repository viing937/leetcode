#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    struct ListNodeCompare {
        bool operator ()(const ListNode *a, const ListNode *b) {
            return a->val < b->val;
        }
    };
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        multiset<ListNode *, ListNodeCompare> queue;
        for (int i = 0; i < lists.size(); i++)
            if (lists[i])
                queue.insert(lists[i]);
        if (queue.empty())
            return NULL;
        ListNode *p = new ListNode(0), *q = p;
        while (!queue.empty()) {
            q = q->next = *queue.begin();
            queue.erase(queue.begin());
            if (q->next)
                queue.insert(q->next);
        }
        q = p->next;
        delete(p);
        return q;
    }
};

int main() {
    return 0;
}
