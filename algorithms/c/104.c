#include <stdio.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root)
{
    if ( root == NULL )
        return 0;
    int l = maxDepth(root->left), r = maxDepth(root->right);
    return (l>r?l:r)+1;
}

int main()
{
    return 0;
}
