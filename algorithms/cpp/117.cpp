#include <iostream>
#include <queue>
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
        if ( root == NULL )
            return;
        queue<TreeLinkNode *> q;
        TreeLinkNode *node;
        q.push(root);
        int cnt1 = 1, cnt2 = 0;
        while ( cnt1 > 0 )
        {
            for ( int i = 0; i < cnt1; ++i )
            {
                node = q.front();
                q.pop();
                if ( i < cnt1-1 )
                    node->next = q.front();
                else
                    node->next = NULL;
                if ( node->left )
                {
                    q.push(node->left);
                    cnt2 += 1;
                }
                if ( node->right )
                {
                    q.push(node->right);
                    cnt2 += 1;
                }
            }
            cnt1 = cnt2, cnt2 = 0;
        }
        return;
    }
};

int main()
{
    return 0;
}
