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
private:
    int result;
    int count(TreeNode *root, int k)
    {
        if ( root == NULL )
            return 0;
        int left = count(root->left, k), right = count(root->right, k-left-1);
        if ( k == left+1 )
            result = root->val;
        return left+right+1;
    }
public:
    int kthSmallest(TreeNode* root, int k)
    {
        count(root, k);
        return result;
    }
};

int main()
{
    return 0;
}
