#include <stdio.h>

int climbStairs(int n)
{
    if ( n == 0 )
        return 0;
    int p, q, t;
    p = q = 1;
    for ( int i = 1; i < n; i++ )
    {
        t = p+q;
        p = q;
        q = t;
    }
    return q;
}

int main()
{
    printf("%d\n", climbStairs(3));
    return 0;
}
