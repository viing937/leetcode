#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        int dp[101][101] = {0};
        for (const auto &s: strs) {
            int zeros = count(s.begin(), s.end(), '0');
            int ones = s.size() - zeros;
            for (int i = m; i >= zeros; i--)
                for (int j = n; j >= ones; j--)
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones] + 1);
        }
        return dp[m][n];
    }
};

int main() {
    return 0;
}
