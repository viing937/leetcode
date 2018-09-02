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
    int helper(TreeNode *root, unordered_map<int, int> &cnt) {
        if (root == NULL)
            return 0;
        int leftSum = helper(root->left, cnt);
        int rightSum = helper(root->right, cnt);
        int treeSum = root->val + leftSum + rightSum;
        cnt[treeSum] += 1;
        return treeSum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        unordered_map<int, int> cnt;
        helper(root, cnt);
        int maxFrequence = 0;
        for (auto p: cnt)
            maxFrequence = max(maxFrequence, p.second);
        vector<int> result;
        for (auto p: cnt)
            if (p.second == maxFrequence)
                result.push_back(p.first);
        return result;
    }
};

int main() {
    return 0;
}
