#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        for (int k = 2; k <= n; k++) {
            for (int i = 1; i+k-1 <= n; i++) {
                dp[i][i+k-1] = INT32_MAX;
                for (int j = i; j <= i+k-1; j++)
                    dp[i][i+k-1] = min(dp[i][i+k-1], j + max(dp[i][j-1], dp[j+1][i+k-1]));
            }
        }
        return dp[1][n];
    }
};

int main() {
    return 0;
}
