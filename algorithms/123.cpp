#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // dp[k, i] represents the max profit up until prices[i] (Note: NOT ending with prices[i]) using at most k transactions.
        // dp[k, i] = max(dp[k, i-1], prices[i] - prices[j] + dp[k-1, j])
        //          = max(dp[k, i-1], prices[i] + max(dp[k-1, j] - prices[j]))
        if (prices.size() == 0)
            return 0;

        int K = 2;
        vector< vector<int> > dp(K+1, vector<int>(prices.size(), 0));
        for (int k = 1; k <= K; k++) {
            int tmpMax = dp[k-1][0] - prices[0];
            for (int i = 0; i < prices.size(); i++) {
                dp[k][i] = max(dp[k][i-1], prices[i] + tmpMax);
                tmpMax = max(tmpMax, dp[k-1][i] - prices[i]);
            }
        }
        return *max_element(dp[K].begin(), dp[K].end());
    }
};

int main() {
    return 0;
}
