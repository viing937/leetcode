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
    TreeNode *helper(const vector<int> &preorder, const vector<int> &inorder, int s1, int e1, int s2, int e2) {
        if (s1 > e1)
            return NULL;

        TreeNode *root = new TreeNode(preorder[s1]);

        for (int i = s2; i <= e2; i++) {
            if (inorder[i] == preorder[s1]) {
                int left = i-s2, right = e2-i;
                root->left = helper(preorder, inorder, s1+1, s1+left, s2, s2+left-1);
                root->right = helper(preorder, inorder, e1-right+1, e1, e2-right+1, e2);
                break;
            }
        }

        return root;
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return helper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};

int main() {
    return 0;
}
