#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = (word1[i-1] == word2[j-1]) ? dp[i-1][j-1]+1
                             : max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int commonLen = dp[m][n];
        return m - commonLen + n - commonLen;
    }
};

int main() {
    return 0;
}
