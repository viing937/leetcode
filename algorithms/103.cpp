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
    void traversal(TreeNode *node, int level, vector<vector<int>> &result) {
        if (node == NULL)
            return;
        if (result.size() <= level)
            result.push_back(vector<int>());
        result[level].push_back(node->val);
        traversal(node->left, level+1, result);
        traversal(node->right, level+1, result);
        return;
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        traversal(root, 0, result);
        for (int i = 1; i < result.size(); i+=2)
            reverse(result[i].begin(), result[i].end());
        return result;
    }
};

int main() {
    return 0;
}
