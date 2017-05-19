#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int dfs(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
        if (dp[i][j] > 1)
            return dp[i][j];
        int n = matrix.size(), m = matrix[0].size();
        if (i-1 >= 0 && matrix[i-1][j] < matrix[i][j])
            dp[i][j] = max(dp[i][j], dfs(i-1, j, matrix, dp)+1);
        if (j-1 >= 0 && matrix[i][j-1] < matrix[i][j])
            dp[i][j] = max(dp[i][j], dfs(i, j-1, matrix, dp)+1);
        if (i+1 < n && matrix[i+1][j] < matrix[i][j])
            dp[i][j] = max(dp[i][j], dfs(i+1, j, matrix, dp)+1);
        if (j+1 < m && matrix[i][j+1] < matrix[i][j])
            dp[i][j] = max(dp[i][j], dfs(i, j+1, matrix, dp)+1);
        return dp[i][j];
    }
public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (matrix.size() == 0)
            return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1));
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result = max(result, dfs(i, j, matrix, dp));
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
