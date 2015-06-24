#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minPathSum(vector< vector<int> >& grid)
    {
        vector<int> dp(grid[0]);
        for ( unsigned int i = 1; i < dp.size(); i++ )
            dp[i] += dp[i-1];
        for ( unsigned int i = 1; i < grid.size(); i++ )
        {
            dp[0] += grid[i][0];
            for ( unsigned int j = 1; j < dp.size(); j++ )
                dp[j] = (dp[j-1]<dp[j]?dp[j-1]:dp[j])+grid[i][j];
        }
        return dp.back();
    }
};

int main()
{
    return 0;
}
