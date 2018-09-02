#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(1, 1);
        int i = 0, j = 0, k = 0;
        while ( (int)dp.size() != n )
        {
            int m = min(dp[i]*2, min(dp[j]*3, dp[k]*5));
            dp.push_back(m);
            if ( m == dp[i]*2 ) i += 1;
            if ( m == dp[j]*3 ) j += 1;
            if ( m == dp[k]*5 ) k += 1;
        }
        return dp.back();
    }
};

int main()
{
    return 0;
}
