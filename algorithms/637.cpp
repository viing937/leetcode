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
    vector<double> sum;
    vector<int> cnt;
    void helper(TreeNode *node, int level) {
        if (node == NULL) return;
        if (level >= sum.size()) {
            sum.push_back(0);
            cnt.push_back(0);
        }
        sum[level] += node->val;
        cnt[level] += 1;
        helper(node->left, level+1);
        helper(node->right, level+1);
    }
public:
    vector<double> averageOfLevels(TreeNode*root) {
        sum.clear();
        cnt.clear();
        helper(root, 0);
        for (int i = 0; i < sum.size(); i++)
            sum[i] /= cnt[i];
        return sum;
    }
};

int main() {
    return 0;
}
