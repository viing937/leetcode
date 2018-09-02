#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        vector<int> result;
        if (nums.empty()) return result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);
        unordered_map<int, int> link;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (nums[j] % nums[i] == 0 && dp[j] <= dp[i]) {
                    dp[j] = dp[i]+1;
                    link[j] = i;
                }
            }
        }
        int maxNum = *max_element(dp.begin(), dp.end());
        for (int i = 0; i < n; i++) {
            if (dp[i] != maxNum) continue;
            int j = i;
            result.push_back(nums[j]);
            while (link.find(j) != link.end()) {
                j = link[j];
                result.push_back(nums[j]);
            }
            reverse(result.begin(), result.end());
            break;
        }
        return result;
    }
};

int main() {
    return 0;
}
