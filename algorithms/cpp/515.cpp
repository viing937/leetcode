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
    void helper(TreeNode *root, int depth, vector<int> &maxVal) {
        if (root == NULL) return;
        if (depth >= maxVal.size())
            maxVal.push_back(root->val);
        else
            maxVal[depth] = max(maxVal[depth], root->val);
        helper(root->left, depth+1, maxVal);
        helper(root->right, depth+1, maxVal);
        return;
    }
public:
    vector<int> largestValues(TreeNode *root) {
        vector<int> maxVal;
        helper(root, 0, maxVal);
        return maxVal;
    }
};

int main() {
    return 0;
}
