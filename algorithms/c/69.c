#include <stdio.h>

int mySqrt(int x)
{
    double guess = 1;
    while ( guess*guess < x-0.01 || guess*guess > x+0.01 )
        guess = (guess+x/guess)/2;
    return (int)guess;
}

int main()
{
    printf("%d\n", mySqrt(2));
    return 0;
}
