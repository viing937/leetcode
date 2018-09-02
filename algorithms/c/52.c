#include <stdio.h>
#include <stdlib.h>

int check(int mark[], int cur, int n)
{
    int i;
    for ( i = n; i > cur; i-- )
    {
        if ( mark[i] == mark[cur] )
            return 0;
        if ( mark[i]+i == mark[cur]+cur )
            return 0;
        if ( mark[i]-i == mark[cur]-cur )
            return 0;
    }
    return 1;
}

void calQueens(int mark[], int cur, int n, int *count)
{
    if ( cur == 0 )
        *count += 1;
    else
    {
        int i;
        for ( i = 1; i <= n; i++ )
        {
            mark[cur] = i;
            if ( check(mark, cur, n) )
                calQueens(mark, cur-1, n, count);
        }
    }
    return;
}

int totalNQueens(int n)
{
    if ( n == 0 )
        return 0;
    int count = 0;
    int *mark = (int *)malloc(sizeof(int)*(n+1));
    calQueens(mark, n, n, &count);
    free(mark);
    return count;
}

int main()
{
    printf("%d\n", totalNQueens(14));
    return 0;
}
