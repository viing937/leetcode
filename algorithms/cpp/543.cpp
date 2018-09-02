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
    int helper(TreeNode *root, int &result) {
        if (root == NULL) return 0;
        int left = helper(root->left, result);
        int right = helper(root->right, result);
        result = max(result, left + right);
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode *root) {
        int result = 0;
        helper(root, result);
        return result;
    }
};

int main() {
    return 0;
}
