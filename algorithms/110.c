#include <stdio.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int judgeBalanced(struct TreeNode *root)
{
    if ( root == NULL )
        return 0;
    int l = judgeBalanced(root->left);
    if ( l == -1 )
        return -1;
    int r = judgeBalanced(root->right);
    if ( r == -1 )
        return -1;
    if ( l-r >= -1 && l-r <= 1 )
        return (l>r?l:r)+1;
    return -1;
}

bool isBalanced(struct TreeNode* root)
{
    return judgeBalanced(root) != -1;
}

int main()
{
    return 0;
}
