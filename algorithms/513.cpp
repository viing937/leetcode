#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int result, depth;
    void helper(TreeNode *node, int depth) {
        if (node == NULL)
            return;
        if (depth > this->depth) {
            this->result = node->val;
            this->depth = depth;
        }
        helper(node->left, depth+1);
        helper(node->right, depth+1);
    }
public:
    int findBottomLeftValue(TreeNode *root) {
        depth = 0;
        helper(root, 1);
        return result;
    }
};

int main() {
    return 0;
}
