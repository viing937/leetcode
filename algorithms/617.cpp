#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (t1 == NULL && t2 == NULL) return NULL;
        TreeNode *root = new TreeNode(0);
        if (t1) root->val += t1->val;
        if (t2) root->val += t2->val;
        root->left = mergeTrees(t1 ? t1->left : NULL, t2 ? t2->left : NULL);
        root->right = mergeTrees(t1 ? t1->right : NULL, t2 ? t2->right : NULL);
        return root;
    }
};

int main() {
    return 0;
}
