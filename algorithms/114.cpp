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
    void flatten(TreeNode* root)
    {
        if ( root == NULL )
            return;
        flatten(root->left), flatten(root->right);
        if ( root->left == NULL )
            return;
        TreeNode *tmp = root->left;
        while ( tmp->right )
            tmp = tmp->right;
        tmp->right = root->right;
        root->right = root->left;
        root->left = NULL;
        return;
    }
};

int main()
{
    return 0;
}
