#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
    TreeNode *solve(vector<int> &nums, int left, int right)
    {
        if ( left > right )
            return NULL;
        int middle = (left+right)/2;
        TreeNode *root = new TreeNode(nums[middle]);
        root->left = solve(nums, left, middle-1);
        root->right = solve(nums, middle+1, right);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        if ( head == NULL )
            return NULL;
        vector<int> nums;
        while ( head )
        {
            nums.push_back(head->val);
            head = head->next;
        }
        return solve(nums, 0, nums.size()-1);
    }
};

int main()
{
    return 0;
}
