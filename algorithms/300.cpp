#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        if ( n == 0 )
            return 0;
        vector<int> dp(n, 1);
        for ( int i = 0; i < n; ++i )
            for ( int j = i+1; j < n; ++j )
                if ( nums[j] > nums[i] )
                    dp[j] = max(dp[j], dp[i]+1);
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    return 0;
}
