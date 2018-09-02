#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode *firstElement, *secondElement;
    TreeNode *prevElement;

    void doSomething(TreeNode *node) {
        if (!firstElement && prevElement && prevElement->val >= node->val)
            firstElement = prevElement;

        if (firstElement && prevElement->val >= node->val)
            secondElement = node;

        prevElement = node;
    }
public:
    void recoverTree(TreeNode *root) {
        firstElement = secondElement = prevElement = NULL;

        TreeNode *cur = root, *prev = NULL;
        while (cur) {
            if (!cur->left) {
                doSomething(cur);
                cur = cur->right;
            } else {
                prev = cur->left;
                while (prev->right && prev->right != cur)
                    prev = prev->right;

                if (prev->right == cur) {
                    prev->right = NULL;
                    doSomething(cur);
                    cur = cur->right;
                } else {
                    prev->right = cur;
                    cur = cur->left;
                }
            }
        }

        swap(firstElement->val, secondElement->val);
        return;
    }
};

int main() {
    return 0;
}
