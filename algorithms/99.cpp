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
    void traverse(TreeNode *root) {
        if (!root)
            return;

        traverse(root->left);

        if (!firstElement && prevElement && prevElement->val >= root->val)
            firstElement = prevElement;

        if (firstElement && prevElement->val >= root->val)
            secondElement = root;

        prevElement = root;

        traverse(root->right);
    }
public:
    void recoverTree(TreeNode *root) {
        firstElement = secondElement = prevElement = NULL;

        traverse(root);

        swap(firstElement->val, secondElement->val);
        return;
    }
};

int main() {
    return 0;
}
