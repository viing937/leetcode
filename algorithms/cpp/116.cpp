#include <iostream>
using namespace std;

struct TreeLinkNode
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
public:
    void connect(TreeLinkNode *root)
    {
        if ( !root )
            return;
        connect(root->left);
        connect(root->right);
        struct TreeLinkNode *l = root->left, *r = root->right;
        while ( l )
        {
            l->next = r;
            l = l->right;
            r = r->left;
        }
        return;
    }
};

int main()
{
    return 0;
}
