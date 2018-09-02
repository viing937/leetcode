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
    int helper(TreeNode *node, int &result) {
        if (node == NULL)
            return 0;
        int left = helper(node->left, result);
        int right = helper(node->right, result);
        result += abs(left-right);
        return left + right + node->val;
    }
public:
    int findTilt(TreeNode *root) {
        int result = 0;
        helper(root, result);
        return result;
    }
};

int main() {
    return 0;
}
