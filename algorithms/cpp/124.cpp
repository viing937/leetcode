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
    int helper(TreeNode *root, int &pathSum) {
        if (root == NULL) return 0;
        int left = max(0, helper(root->left, pathSum));
        int right = max(0, helper(root->right, pathSum));
        pathSum = max(pathSum, left + right + root->val);
        return max(left, right) + root->val;
    }
public:
    int maxPathSum(TreeNode *root) {
        int pathSum = INT32_MIN;
        helper(root, pathSum);
        return pathSum;
    }
};

int main() {
    return 0;
}
