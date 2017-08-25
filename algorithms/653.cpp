#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool helper(TreeNode *node, int k, unordered_map<int, bool> &m) {
        if (node == NULL) return false;
        if (m.find(k - node->val) != m.end()) return true;
        m[node->val] = true;
        return helper(node->left, k, m) || helper(node->right, k, m);
    }
public:
    bool findTarget(TreeNode *root, int k) {
        unordered_map<int, bool> m;
        return helper(root, k, m);
    }
};

int main() {
    return 0;
}
