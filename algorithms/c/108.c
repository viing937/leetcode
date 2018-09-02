#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    if ( numsSize == 0 )
        return NULL;
    struct TreeNode *tree = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    int m = numsSize/2;
    tree->val = nums[m];
    tree->left = sortedArrayToBST(nums, m);
    tree->right = sortedArrayToBST(nums+m+1, numsSize-m-1);
    return tree;
}

int main()
{
    return 0;
}
