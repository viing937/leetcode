#include <stdio.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countNodes(struct TreeNode* root)
{
    if( root == NULL )
        return 0;

    int heightL = 0, heightR = 0;
    struct TreeNode *p;
    p = root;
    while( p != NULL )
    {
        heightL++;
        p = p->left;
    } 

    p = root;
    while( p != NULL )
    {
        heightR++;
        p = p->right;
    }

    if( heightL == heightR )
        return (1<<heightL)-1;
    return 1 + countNodes(root->left)+countNodes(root->right);
}

int main()
{
    return 0;
}
