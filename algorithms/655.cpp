#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    const vector<int> pow2 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    int getMaxDepth(TreeNode *root) {
        if (root == NULL) return 0;
        return max(getMaxDepth(root->left), getMaxDepth(root->right)) + 1;
    }
    void printTree(TreeNode *root, int depth, int left, int right, vector<vector<string>> &result) {
        if (root == NULL) return;
        int mid = left + (right-left) / 2;
        result[depth][mid] = to_string(root->val);
        printTree(root->left, depth+1, left, mid-1, result);
        printTree(root->right, depth+1, mid+1, right, result);
        return;
    }
public:
    vector<vector<string>> printTree(TreeNode *root) {
        int depth = getMaxDepth(root);
        int width = pow2[depth] - 1;
        vector<vector<string>> result(depth, vector<string>(width, ""));
        printTree(root, 0, 0, width-1, result);
        return result;
    }
};

int main() {
    return 0;
}
