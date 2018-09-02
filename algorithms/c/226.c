#include <stdio.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root)
{
    if ( root != NULL )
    {
        struct TreeNode *t = root->left;
        root->left = root->right;
        root->right = t;
        invertTree(root->left);
        invertTree(root->right);
    }
    return root;
}

int main()
{
    return 0;
}
