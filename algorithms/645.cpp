#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        int n = nums.size();
        vector<int> result(2);
        for (int i = 0; i < n; i++) {
            while (nums[nums[i]-1] != nums[i])
                swap(nums[nums[i]-1], nums[i]);
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i+1) {
                result[0] = nums[i];
                result[1] = i+1;
                break;
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {3, 2, 2};
    Solution solution;
    solution.findErrorNums(nums);
    return 0;
}
