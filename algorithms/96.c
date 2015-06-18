#include <stdio.h>

int numTrees(int n)
{
    if ( n == 0 )
        return 0;
    int i;
    long long ans = 1;
    for ( i = 1; i <= n; i++ )
        ans = ans*(4*i-2)/(i+1);
    return (int)ans;
}

int main()
{
    printf("%d\n", numTrees(19));
    return 0;
}
