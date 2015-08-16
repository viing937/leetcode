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
    void dfs(vector<string> &result, string s, TreeNode *root)
    {
        s = s+"->"+to_string(root->val);
        if ( root->left == NULL && root->right == NULL )
            result.push_back(s.substr(2));
        else
        {
            if ( root->left )
                dfs(result, s, root->left);
            if ( root->right )
                dfs(result, s, root->right);
        }
        return;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> result;
        if ( root == NULL )
            return result;
        dfs(result, "", root);
        return result;
    }
};

int main()
{
    return 0;
}
