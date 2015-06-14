#include <stdio.h>
#include <stdint.h>

int hammingWeight(uint32_t n)
{
    int i;
    int ans = 0;
    int temp = 1;
    for ( i = 0; i < 32; i++ )
    {
        if ( n&temp<<(31-i) )
            ans++;
    }
    return ans;
}

int main()
{
    printf("%d\n", hammingWeight((unsigned int)11));
    return 0;
}
