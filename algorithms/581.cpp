#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int n = nums.size();
        int left = -1, right = -2;
        for (int i = 0, m = nums[0]; i < n; i++) {
            if (nums[i] < m)
                right = i;
            m = max(m, nums[i]);
        }
        for (int i = n-1, m = nums[n-1]; i >= 0; i--) {
            if (nums[i] > m)
                left = i;
            m = min(m, nums[i]);
        }
        return right-left+1;
    }
};

int main() {
    return 0;
}
