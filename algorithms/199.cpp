#include <iostream>
#include <vector>
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
    void dfs(TreeNode *root, vector<int> &result, int h)
    {
        if ( h > (int)result.size() )
            result.push_back(root->val);
        if ( root->right )
            dfs(root->right, result, h+1);
        if ( root->left )
            dfs(root->left, result, h+1);
    }
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> result;
        if ( root == NULL )
            return result;
        dfs(root, result, 1);
        return result;
    }
};

int main()
{
    return 0;
}
