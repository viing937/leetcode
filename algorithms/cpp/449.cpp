#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    TreeNode *BSTinsert(TreeNode *root, int val) {
        if (root == NULL)
            root = new TreeNode(val);
        else if (val < root->val)
            root->left = BSTinsert(root->left, val);
        else
            root->right = BSTinsert(root->right, val);
        return root;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == NULL)
            return "";
        string data = to_string(root->val);
        if (root->left)
            data = data + "," + serialize(root->left);
        if (root->right)
            data = data + "," + serialize(root->right);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        if (n == 0)
            return NULL;
        TreeNode *root = NULL;
        for (int i = 0; i < n; i++) {
            int num = atoi(data.c_str()+i);
            while (i < n && data[i] != ',')
                i += 1;
            root = BSTinsert(root, num);
        }
        return root;
    }
};

int main() {
    return 0;
}
