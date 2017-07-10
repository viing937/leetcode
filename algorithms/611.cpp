#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int result = 0, n = nums.size();
        for (int i = n-1; i > 1; i--) {
            int l = 0, r = i-1;
            while (l < r) {
                if (nums[l] + nums[r] > nums[i]) {
                    result += r-l;
                    r -= 1;
                }
                else
                    l += 1;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
