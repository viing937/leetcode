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
    void dfs(int start, int end, vector<TreeNode *> &result, vector< vector< vector<TreeNode *> > > &dp)
    {
        if ( start > end )
        {
            result.push_back(NULL);
            return;
        }
        if ( !dp[start-1][end-1].empty() )
        {
            result = dp[start-1][end-1];
            return;
        }
        for ( int i = start; i <= end; ++i )
        {
            vector<TreeNode *> left, right;
            dfs(start, i-1, left, dp);
            dfs(i+1, end, right, dp);
            for ( auto left_node = left.begin(); left_node != left.end(); ++left_node )
            {
                for ( auto right_node = right.begin(); right_node != right.end(); ++right_node )
                {
                    TreeNode *node = new TreeNode(i);
                    node->left = *left_node;
                    node->right = *right_node;
                    result.push_back(node);
                }
            }
        }
        dp[start-1][end-1] = result;
        return;
    }
public:
    vector<TreeNode*> generateTrees(int n)
    {
        vector<TreeNode *> result;
        vector< vector< vector<TreeNode *> > > dp(n, vector< vector<TreeNode *> >(n));
        dfs(1, n, result, dp);
        return result;
    }
};

int main()
{
    return 0;
}
