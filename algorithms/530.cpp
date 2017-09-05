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
    int helper(TreeNode *root) {
        int result = INT32_MAX;
        if (root->left) {
            TreeNode *node = root->left;
            while (node->right) node = node->right;
            result = min(result, root->val - node->val);
            result = min(result, helper(root->left));
        }
        if (root->right) {
            TreeNode *node = root->right;
            while (node->left) node = node->left;
            result = min(result, node->val - root->val);
            result = min(result, helper(root->right));
        }
        return result;
    }
public:
    int getMinimumDifference(TreeNode *root) {
        return helper(root);
    }
};

int main() {
    return 0;
}
