#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        if (n == 0) return true;
        vector<vector<bool>> dp(n, vector<bool>(n, true));
        for (int i = 0; i < n; i++) dp[i][i] = s[i] == '*';
        for (int k = 2; k <= n; k++) {
            for (int i = 0; i+k-1 < n; i++) {
                int l = i, r = i+k-1;
                dp[l][r] = false;
                if (dp[l+1][r-1] && (s[l] == '*' || s[l] == '(')
                                 && (s[r] == '*' || s[r] == ')')) {
                    dp[l][r] = true;
                    continue;
                }
                for (int j = l; j < r; j++) {
                    if (dp[l][j] && dp[j+1][r]) {
                        dp[l][r] = true;
                        break;
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};

int main() {
    return 0;
}
