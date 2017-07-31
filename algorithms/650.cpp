#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = dp[1] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 2; i*j <= n; j += 1)
                dp[i*j] = min(dp[i*j], dp[i] + j);
        }
        return dp[n];
    }
};

int main() {
    return 0;
}
