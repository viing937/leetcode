#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &A) {
        int n = A.size();

        if (n == 0)
            return 0;

        vector< unordered_map<long long, int> > dp(n);
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = (long long)A[i] - A[j];
                dp[i][diff] += 1;
                if (dp[j].find(diff) != dp[j].end()) {
                    dp[i][diff] += dp[j][diff];
                    result += dp[j][diff];
                }
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
