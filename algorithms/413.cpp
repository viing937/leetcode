#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &A) {
        int n = A.size();
        vector<int> dp(n);
        for (int i = 2; i < n; i++) {
            if (A[i]-A[i-1] == A[i-1]-A[i-2]) {
                dp[i] = dp[i-1]+1;
            }
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += dp[i];
        }
        return result;
    }
};

int main() {
    return 0;
}
