#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        if (n <= 1) return 0;
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));
        for (int i = n-2; i >= 0; i--) {
            for (int j = i+1; j < n; j++) {
                if (s[i] != s[j]) continue;
                if (j - i < 3 || palindrome[i+1][j-1])
                    palindrome[i][j] = true;
            }
        }
        vector<int> dp(n, 0);
        for (int i = 1; i < n;i ++) {
            if (palindrome[0][i]) continue;
            dp[i] = 1 + dp[i-1];
            for (int j = 1; j < i; j++) {
                if (palindrome[j][i])
                    dp[i] = min(dp[i], dp[j-1] + 1);
            }
        }
        return dp[n-1];
    }
};

int main() {
    return 0;
}
