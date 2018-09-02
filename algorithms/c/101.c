#include <stdio.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool equal(struct TreeNode *a, struct TreeNode *b)
{
    if ( a && b )
    {
        if ( a->val == b->val && equal(a->left, b->right) && equal(a->right, b->left) )
            return true;
        else
            return false;
    }
    else if ( !a && !b )
        return true;
    else
        return false;
}

bool isSymmetric(struct TreeNode* root)
{
    if ( !root )
        return true;
    else
        return equal(root->left, root->right);
}

int main()
{
    return 0;
}
