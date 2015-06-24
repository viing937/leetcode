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
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> result;
        stack<struct TreeNode *> s;
        struct TreeNode *cur, *pre;
        cur = root;
        pre = NULL;
        while ( cur || !s.empty() )
        {
            while ( cur )
            {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            if ( cur->right == NULL || cur->right == pre )
            {
                result.push_back(cur->val);
                pre = cur;
                s.pop();
                cur = NULL;
            }
            else
                cur = cur->right;
        }
        return result;
    }
};

int main()
{
    return 0;
}
