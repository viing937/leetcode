#include <iostream>
#include <vector>
#include <stack>
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
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        stack<struct TreeNode *> s;
        struct TreeNode *p = root;
        while ( p || !s.empty() )
        {
            while ( p )
            {
                s.push(p);
                ans.push_back(p->val);
                p = p->left;
            }
            p = s.top();
            s.pop();
            p = p->right;
        }
        return ans;
    }
};

int main()
{
    return 0;
}
