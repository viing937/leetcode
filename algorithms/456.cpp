#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int> &nums) {
        int n = nums.size();
        int s3 = INT_MIN;
        stack<int> s;
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] < s3) return true;
            while (!s.empty() && s.top() < nums[i]) {
                s3 = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};

int main () {
    vector<int> nums = {1, 5, 0, 3};
    Solution solution;
    solution.find132pattern(nums);
    return 0;
}
