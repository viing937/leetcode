#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n <= 1) return 0;
        vector<int> dp(n+1, 0);
        for (int i = 2; i <= n; i++) {
            if (s[i-1] == '(') continue;
            if (s[i-2] == '(')
                dp[i] = dp[i-2] + 2;
            else if (s[i-dp[i-1]-2] == '(')
                dp[i] = dp[i-dp[i-1]-2] + dp[i-1] + 2;
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    return 0;
}
