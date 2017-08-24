#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target%2) return false;
        target /= 2;
        vector<bool> dp(target+1, false);
        dp[0] = true;
        for (auto num: nums)
            for (int i = target; i >= num; i--)
                dp[i] = dp[i] || dp[i-num];
        return dp[target];
    }
};

int main() {
    return 0;
}
