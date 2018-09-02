#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid)
    {
        if ( obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0 )
            return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if ( obstacleGrid[0][0] || obstacleGrid[m-1][n-1] )
            return 0;
        vector<int> dp(m);
        dp[0] = 1;
        for ( int i = 1; i < m; ++i )
        {
            if ( obstacleGrid[i][0] )
                dp[i] = 0;
            else
                dp[i] = dp[i-1];
        }
        for ( int i = 1; i < n; ++i )
        {
            for ( int j = 0; j < m; ++j )
            {
                if ( obstacleGrid[j][i] )
                    dp[j] = 0;
                else if ( j > 0 )
                    dp[j] += dp[j-1];
            }
        }
        return dp[m-1];
    }
};

int main()
{
    return 0;
}
