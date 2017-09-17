#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findSecondMinimumValue(TreeNode *root) {
        if (root == NULL || root->left == NULL) return -1;
        int l = root->val == root->left->val ? findSecondMinimumValue(root->left) : root->left->val,
            r = root->val == root->right->val ? findSecondMinimumValue(root->right) : root->right->val;
        if (l == -1) return r;
        if (r == -1) return l;
        return min(l, r);
    }
};

int main() {
    return 0;
}
