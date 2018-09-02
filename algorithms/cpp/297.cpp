#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == NULL) return "";
        return "[" + to_string(root->val) + "," +
                     serialize(root->left) + "," +
                     serialize(root->right) + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        int n = data.size();
        if (n == 0) return NULL;
        vector<int> idx;
        for (int i = 1, count = 0; i < n; i++) {
            if (data[i] == ',' && count == 0) {
                idx.push_back(i);
                if (idx.size() == 2) break;
            }
            else if (data[i] == '[')
                count += 1;
            else if (data[i] == ']')
                count -= 1;
        }
        TreeNode *root = new TreeNode(stoi(data.substr(1, idx[0]-1)));
        root->left = deserialize(data.substr(idx[0]+1, idx[1]-idx[0]-1));
        root->right = deserialize(data.substr(idx[1]+1, n-idx[1]-2));
        return root;
    }
};

int main() {
    return 0;
}
