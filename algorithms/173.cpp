#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator
{
private:
    stack<TreeNode *> tnode;
public:
    BSTIterator(TreeNode *root)
    {
        while ( root )
        {
            tnode.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !tnode.empty();
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *node = tnode.top();
        tnode.pop();
        if ( node->right != NULL )
        {
            TreeNode *rnode = node->right;
            while ( rnode )
            {
                tnode.push(rnode);
                rnode = rnode->left;
            }
        }
        return node->val;
    }
};

int main()
{
    return 0;
}
