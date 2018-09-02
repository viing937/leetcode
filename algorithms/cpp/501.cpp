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
    int count, maxCount;
    TreeNode *prev;
    vector<int> result;

    void inorder(TreeNode *node) {
        if (node == NULL)
            return;

        inorder(node->left);

        count = prev->val == node->val ? count+1 : 1;
        if (count == maxCount)
            result.push_back(node->val);
        else if (count > maxCount) {
            maxCount = count;
            result.clear();
            result.push_back(node->val);
        }
        prev = node;

        inorder(node->right);
    }
public:
    vector<int> findMode(TreeNode *root) {
        count = 0, maxCount = -1;
        prev = root;
        result.clear();
        inorder(root);
        return result;
    }
};

int main() {
    return 0;
}
