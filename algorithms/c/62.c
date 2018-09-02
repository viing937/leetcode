#include <stdio.h>
#include <stdlib.h>

int uniquePaths(int m, int n)
{
    int *dp = (int *)malloc(sizeof(int)*m);
    for ( int i = 0; i < m; i++ )
        dp[i] = 1;
    for ( int i = 1; i < n; i++ )
        for ( int j = 1; j < m; j++ )
            dp[j] += dp[j-1];
    int result = dp[m-1];
    free(dp);
    return result;
}

int main()
{
    printf("%d\n", uniquePaths(3, 7));
    return 0;
}
