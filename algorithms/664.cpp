#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        if (n <= 1) return n;
        vector<vector<int>> dp(101, vector<int>(101, 0));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int i = n-2; i >= 0; i--) {
            for (int j = i+1; j < n; j++) {
                dp[i][j] = dp[i+1][j] + 1;
                for (int k = i+1; k <= j; k++)
                    if (s[k] == s[i])
                        dp[i][j] = min(dp[i][j], dp[i][k-1]+dp[k+1][j]);
            }
        }
        return dp[0][n-1];
    }
};

int main() {
    Solution solution;
    solution.strangePrinter("baacdddaaddaaaaccbddbcabdaabdbbcdcbbbacbddcabcaaa");
    return 0;
}
