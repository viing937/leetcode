#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return root;
        else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else if (root->left && root->right) {
            TreeNode *tmp = root->right, *min;
            if (!tmp->left) {
                min = tmp;
                root->right = tmp->right;
            }
            else {
                min = tmp->left;
                while (min->left) {
                    tmp = min;
                    min = min->left;
                }
                tmp->left = min->right;
            }
            tmp = root;
            root = min;
            root->left = tmp->left;
            root->right = tmp->right;
            delete tmp;
        }
        else {
            TreeNode *tmp = root;
            if (root->left)
                root = root->left;
            else if (root->right)
                root = root->right;
            else
                root = NULL;
            delete tmp;
        }
        return root;
    }
};

int main() {
    return 0;
}
