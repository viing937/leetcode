#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int helper(const vector<int> &nums, int S, int idx, vector<unordered_map<int, int>> &dp) {
        if (idx >= nums.size())
            return S==0 ? 1 : 0;
        if (dp[idx].find(S) != dp[idx].end())
            return dp[idx][S];
        dp[idx][S] = helper(nums, S-nums[idx], idx+1, dp) + helper(nums, S+nums[idx], idx+1, dp);
        return dp[idx][S];
    }
public:
    int findTargetSumWays(vector<int> &nums, int S) {
        vector<unordered_map<int, int>> dp(nums.size());
        return helper(nums, S, 0, dp);
    }
};

int main() {
    return 0;
}
