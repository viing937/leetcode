#include <stdio.h>
#include <stdbool.h>

bool isHappy(int n)
{
    while ( true )
    {
        if ( n == 1 )
            return true;
        if ( n == 4 )
            return false;
        int sum = 0;
        while ( n )
        {
            sum += (n%10)*(n%10);
            n /= 10;
        }
        n = sum;
    }
}

int main()
{
    isHappy(9);
    return 0;
}
