#include <stdio.h>

int min(int a, int b)
{
    return a<b ? a : b;
}

int max(int a, int b)
{
    return a>b ? a : b;
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int SA = (C-A)*(D-B);
    int SB = (G-E)*(H-F);
    if ( E >= C || A >= G || F >= D || B >= H )
        return SA + SB;
    else
    {
        int x1 = max(A, E);
        int x2 = min(C, G);
        int y1 = max(B, F);
        int y2 = min(D, H);
        return SA + SB - (x2-x1)*(y2-y1);
    }
}

int main()
{
    return 0;
}
