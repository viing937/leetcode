#include <stdio.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if ( p == NULL && q == NULL )
        return true;
    if ( (p==NULL) != (q==NULL) )
        return false;
    if ( isSameTree(p->left,q->left) && isSameTree(p->right, q->right) && p->val == q->val )
        return true;
    else
        return false;
}

int main()
{
    return 0;
}
