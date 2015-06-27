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
    void go(vector< vector<int> > &result, struct TreeNode *root, int depth)
    {
        if ( !root )
            return;
        if ( depth >= (int)result.size() )
        {
            vector<int> level;
            level.push_back(root->val);
            result.push_back(level);
        }
        else
        {
            result[depth].push_back(root->val);
        }
        go(result, root->left, depth+1);
        go(result, root->right, depth+1);
    }
public:
    vector< vector<int> > levelOrder(TreeNode* root)
    {
        vector< vector<int> > result;
        go(result, root, 0);
        return result;
    }
};

int main()
{
    return 0;
}
