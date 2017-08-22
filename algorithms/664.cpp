#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        if (n <= 1) return n;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int i = n-2; i >= 0; i--) {
            for (int j = i+1; j < n; j++) {
                dp[i][j] = dp[i+1][j] + 1;
                for (int k = i; k < j; k++)
                    if (s[k+1] == s[i])
                        dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]-1);
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
