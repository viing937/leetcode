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
public:
    bool isValidBST(TreeNode* root)
    {
        if ( !root )
            return true;
        if ( !isValidBST(root->left) || !isValidBST(root->right) )
            return false;
        if ( root->left )
        {
            TreeNode *max_left = root->left;
            while ( max_left->right )
                max_left = max_left->right;
            if ( max_left->val >= root->val )
                return false;
        }
        if ( root->right )
        {
            TreeNode *min_right = root->right;
            while ( min_right->left )
                min_right = min_right->left;
            if ( min_right->val <= root->val )
                return false;
        }
        return true;
    }
};

int main()
{
    return 0;
}
