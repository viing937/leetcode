#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == nums[mid-1]) {
                if ((mid-left-1) % 2)
                    right = mid - 2;
                else
                    left = mid + 1;
            }
            else if (nums[mid] == nums[mid+1]) {
                if ((mid-left) % 2)
                    right = mid - 1;
                else
                    left = mid + 2;
            }
            else
                return nums[mid];
        }
        return nums[left];
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 2, 4, 4, 5, 5, 9};
    Solution solution;
    solution.singleNonDuplicate(nums);
    return 0;
}
