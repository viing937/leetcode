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
    unordered_map<TreeNode *, int> cache;
    int helper(TreeNode *root) {
        if (root == NULL)
            return 0;
        if (cache.find(root) != cache.end())
            return cache[root];

        cache[root] = root->val;
        if (root->left)
            cache[root] += helper(root->left->left) + helper(root->left->right);
        if (root->right)
            cache[root] += helper(root->right->left) + helper(root->right->right);
        
        cache[root] = max(cache[root], helper(root->left) + helper(root->right));
        return cache[root];
    }
public:
    int rob(TreeNode *root) {
        if (root == NULL)
            return 0;
        cache.clear();
        return helper(root);
    }
};

int main() {
    return 0;
}
