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
    TreeNode *helper(int left, int right, vector<int> &nums) {
        if (left > right) return NULL;
        int middle = left;
        for (int i = left; i <= right; i++)
            if (nums[i] > nums[middle])
                middle = i;
        TreeNode *root = new TreeNode(nums[middle]);
        root->left = helper(left, middle-1, nums);
        root->right = helper(middle+1, right, nums);
        return root;
    }
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return helper(0, nums.size()-1, nums);
    }
};

int main() {
    return 0;
}
