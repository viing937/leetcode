#include <stdio.h>
#include <stdbool.h>
#define BADVERSION 30

bool isBadVersion(int version)
{
    if ( version > BADVERSION )
        return true;
    else
        return false;
}

int firstBadVersion(int n)
{
    int l = 1, r = n;
    while ( l < r )
    {
        int m = l+(r-l)/2;
        if ( isBadVersion(m) )
            r = m;
        else
            l = m+1;
    }
    return l;
}

int main()
{
    return 0;
}
