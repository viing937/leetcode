#include <stdio.h>

int min(int a, int b)
{
    return a<b ? a : b;
}

int max(int a, int b)
{
    return a>b ? a : b;
}

int maxArea(int* height, int heightSize)
{
    int ans = 0;
    int i = 0, j = heightSize-1;
    while ( i < j )
    {
        int h = min(height[i], height[j]);
        ans = max(ans, h*(j-i));
        while ( height[i] <= h )
            i++;
        while ( height[j] <= h )
            j--;
    }
    return ans;
}

int main()
{
    return 0;
}
