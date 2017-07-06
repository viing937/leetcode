#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void helper(TreeNode *root, int v, int d, int cur) {
        if (root == NULL)
            return;
        if (cur == d-1) {
            TreeNode *newLeft = new TreeNode(v), *newRight = new TreeNode(v);
            newLeft->left = root->left;
            newRight->right = root->right;
            root->left = newLeft;
            root->right = newRight;
        }
        else {
            helper(root->left, v, d, cur+1);
            helper(root->right, v, d, cur+1);
        }
        return;
    }
public:
    TreeNode *addOneRow(TreeNode *root, int v, int d) {
        if (d == 1) {
            TreeNode *newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        helper(root, v, d, 1);
        return root;
    }
};

int main() {
    return 0;
}
