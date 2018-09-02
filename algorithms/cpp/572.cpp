#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool isEqual(const TreeNode *a, const TreeNode *b) {
        if (a == NULL && b == NULL)
            return true;
        return a != NULL && b != NULL && a->val == b->val &&
               isEqual(a->left, b->left) &&
               isEqual(a->right, b->right);
    }
public:
    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (isEqual(s, t))
            return true;
        if (s == NULL)
            return false;
        if (isSubtree(s->left, t))
            return true;
        if (isSubtree(s->right, t))
            return true;
        return false;
    }
};

int main() {
    return 0;
}
