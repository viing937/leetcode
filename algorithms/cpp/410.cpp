#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    long getSum(int s, int e, const vector<long> &psum) {
        return psum[e]-psum[s-1];
    }
public:
    int splitArray(vector<int> &nums, int m) {
        vector<long> psum(1, 0);
        for (int i = 0; i < nums.size(); i++)
            psum.push_back(psum.back()+nums[i]);
        vector<vector<long>> dp(m, vector<long>(nums.size()+1, LONG_MAX));
        dp[0] = psum;
        for (int i = 1; i < m; i++) {
            for (int j = 0; j <= i; j++)
                dp[i][j] = 0;
            for (int j = 0; j < dp[i].size(); j++) {
                for (int k = j+1; k < dp[i].size(); k++)
                    dp[i][k] = min(dp[i][k], max(dp[i-1][j], getSum(j+1, k, psum)));
            }
        }
        return dp[m-1].back();
    }
};

int main() {
    vector<int> nums = {7, 2, 5, 10, 8};
    Solution solution;
    cout << solution.splitArray(nums, 2) << endl;
    return 0;
}
