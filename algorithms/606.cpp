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
    string helper(TreeNode *node) {
        string s = "";
        if (node == NULL) return s;
        s += to_string(node->val);
        if (node->left != NULL || node->right != NULL) s += "(" + helper(node->left) + ")";
        if (node->right != NULL) s += "(" + helper(node->right) + ")";
        return s;
    }
public:
    string tree2str(TreeNode *t) {
        return helper(t);
    }
};

int main() {
    return 0;
}
