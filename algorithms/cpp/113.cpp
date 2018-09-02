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
    void dfs(vector< vector<int> > &result, vector<int> &temp, TreeNode *root, int sum)
    {
        sum -= root->val;
        temp.push_back(root->val);
        if ( root->left == NULL && root->right == NULL && sum == 0 )
            result.push_back(temp);
        if ( root->left )
            dfs(result, temp, root->left, sum);
        if ( root->right )
            dfs(result, temp, root->right, sum);
        temp.pop_back();
        return;
    }
public:
    vector< vector<int> > pathSum(TreeNode* root, int sum)
    {
        vector< vector<int> > result;
        vector<int> temp;
        if ( root )
            dfs(result, temp, root, sum);
        return result;
    }
};

int main()
{
    return 0;
}
