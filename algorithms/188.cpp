#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int K, vector<int> &prices) {
        // dp[k, i] represents the max profit up until prices[i] (Note: NOT ending with prices[i]) using at most k transactions.
        // dp[k, i] = max(dp[k, i-1], prices[i] - prices[j] + dp[k-1, j])
        //          = max(dp[k, i-1], prices[i] + max(dp[k-1, j] - prices[j]))
        if (prices.size() == 0)
            return 0;
        if (K >= prices.size()/2) {
            int result = 0;
            for (int i = 1; i < prices.size(); i++)
                result += max(0, prices[i]-prices[i-1]);
            return result;
        }
        vector<vector<int>> dp(2, vector<int>(prices.size(), 0));
        for (int k = 1; k <= K; k++) {
            int tmpMax = dp[(k-1)%2][0] - prices[0];
            for (int i = 0; i < prices.size(); i++) {
                dp[k%2][i] = max(dp[k%2][i-1], prices[i] + tmpMax);
                tmpMax = max(tmpMax, dp[(k-1)%2][i] - prices[i]);
            }
        }
        return *max_element(dp[K%2].begin(), dp[K%2].end());
    }
};

int main() {
    return 0;
}
