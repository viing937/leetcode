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
    void helper(TreeNode *node, int &acc) {
        if (node == NULL)
            return;
        helper(node->right, acc);
        acc = node->val = acc + node->val;
        helper(node->left, acc);
        return;
    }
public:
    TreeNode *convertBST(TreeNode *root) {
        int acc = 0;
        helper(root, acc);
        return root;
    }
};

int main() {
    return 0;
}
