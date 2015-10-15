#include <iostream>
#include <vector>
#include <algorithm>
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
    TreeNode *helper(vector<int> &inorder, int l_in, int r_in, vector<int> &postorder, int l_post, int r_post)
    {
        if ( l_in >= r_in )
            return NULL;
        TreeNode *root = new TreeNode(postorder[r_post-1]);
        int len_left = find(inorder.begin()+l_in, inorder.begin()+r_in, root->val)-inorder.begin()-l_in;

        root->left = helper(inorder, l_in, l_in+len_left, postorder, l_post, l_post+len_left);
        root->right = helper(inorder, l_in+len_left+1, r_in, postorder, l_post+len_left, r_post-1);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return helper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};

int main()
{
    vector<int> inorder = {1, 2}, postorder = {1, 2};
    Solution solution;
    solution.buildTree(inorder, postorder);
    return 0;
}
