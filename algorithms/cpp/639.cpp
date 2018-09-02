#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    const int MOD = 1000000007;
    unordered_map<string, int> preCount() {
        unordered_map<string, int> m;
        for (int i = 1; i <= 9; i++) {
            m[to_string(i)] += 1;
            m["*"] += 1;
        }
        for (int i = 10; i <= 26; i++) {
            string ten = to_string(i/10);
            string one = to_string(i%10);
            m[ten+one] += 1;
            m["*"+one] += 1;
            if (one == "0") continue;
            m[ten+"*"] += 1;
            m["**"] += 1;
        }
        return m;
    }
public:
    int numDecodings(string s) {
        if (s.size() == 0) return 0;
        unordered_map<string, int> m = preCount();
        int n = s.size();
        vector<long> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = m[s.substr(0, 1)];
        for (int i = 2; i <= n; i++) {
            dp[i] += dp[i-1] * m[s.substr(i-1, 1)];
            dp[i] += dp[i-2] * m[s.substr(i-2, 2)];
            dp[i] %= MOD;
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    solution.numDecodings("1*");
    return 0;
}
