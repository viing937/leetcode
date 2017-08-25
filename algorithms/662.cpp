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
    void helper(TreeNode *root, int idx, int depth, vector<pair<int, int>> &depthWidth) {
        if (root == NULL) return;
        if (depth >= depthWidth.size())
            depthWidth.emplace_back(idx, idx);
        depthWidth[depth].first = min(depthWidth[depth].first, idx);
        depthWidth[depth].second = max(depthWidth[depth].second, idx);
        helper(root->left, idx*2, depth+1, depthWidth);
        helper(root->right, idx*2+1, depth+1, depthWidth);
        return;
    }
public:
    int widthOfBinaryTree(TreeNode *root) {
        vector<pair<int, int>> depthWidth;
        helper(root, 1, 0, depthWidth);
        int result = INT_MIN;
        for (auto &p: depthWidth)
            result = max(result, p.second - p.first + 1);
        return result;
    }
};

int main() {
    return 0;
}
