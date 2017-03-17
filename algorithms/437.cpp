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
    int cnt;
public:
    int pathSum(TreeNode *root, int sum) {
        cnt = 0;
        if (root)
            helper(root, sum);
        return cnt;
    }

    void helper(TreeNode *root, int sum) {
        sumTree(root, sum);
        if (root->left)
            helper(root->left, sum);
        if (root->right)
            helper(root->right, sum);
    }

    void sumTree(TreeNode *root, int sum) {
        if (root->val == sum)
            cnt += 1;
        if (root->left)
            sumTree(root->left, sum - root->val);
        if (root->right)
            sumTree(root->right, sum - root->val);
    }
};

int main()
{
    return 0;
}
