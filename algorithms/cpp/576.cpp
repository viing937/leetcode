#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    const int MOD = 1000000007;
public:
    int findPaths(int m, int n, int N, int x, int y) {
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(m, vector<int>(n, 0)));
        dp[0][x][y] = 1;
        int result = 0;
        for (int k = 1; k <= N; k++) {
            int src = 1-k%2, des = 1-src;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == 0) result = (result + dp[src][i][j]) % MOD;
                    if (j == 0) result = (result + dp[src][i][j]) % MOD;
                    if (i == m-1) result = (result + dp[src][i][j]) % MOD;
                    if (j == n-1) result = (result + dp[src][i][j]) % MOD;
                    dp[des][i][j] = 0;
                    if (i-1 >= 0) dp[des][i][j] = (dp[des][i][j] + dp[src][i-1][j]) % MOD;
                    if (j-1 >= 0) dp[des][i][j] = (dp[des][i][j] + dp[src][i][j-1]) % MOD;
                    if (i+1 < m) dp[des][i][j] = (dp[des][i][j] + dp[src][i+1][j]) % MOD;
                    if (j+1 < n) dp[des][i][j] = (dp[des][i][j] + dp[src][i][j+1]) % MOD;
                }
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
