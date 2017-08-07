#include <iostream>
#include <vector>
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
    unordered_map<string, vector<TreeNode *>> m;
    string serialize(TreeNode *node) {
        if (node == NULL) return "";
        string s = "(" + serialize(node->left) + to_string(node->val) + serialize(node->right) + ")";
        m[s].push_back(node);
        return s;
    }
public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        m.clear();
        serialize(root);
        vector<TreeNode *> result;
        for (auto &p: m) {
            if (p.second.size() > 1)
                result.push_back(p.second[0]);
        }
        return result;
    }
};

int main() {
    return 0;
}
