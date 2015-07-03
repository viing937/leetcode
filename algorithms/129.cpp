#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    void cal(TreeNode *root, int &sum)
    {
        sum = sum*10+root->val;
        if ( !root->left && !root->right )
            return;
        else if ( !root->left )
            cal(root->right, sum);
        else if ( !root->right )
            cal(root->left, sum);
        else
        {
            int sum_left, sum_right;
            sum_left = sum_right = sum;
            cal(root->left, sum_left);
            cal(root->right, sum_right);
            sum = sum_left + sum_right;
        }
    }
public:
    int sumNumbers(TreeNode* root)
    {
        if ( !root )
            return 0;
        int sum = 0;
        cal(root, sum);
        return sum;
    }
};

int main()
{
    return 0;
}
