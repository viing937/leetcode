#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countPrimes(int n)
{
    int count = 0;
    int *nonPrime = (int *)malloc(sizeof(int)*n);
    int *prime = (int *)malloc(sizeof(int)*n);
    memset(nonPrime, 0, sizeof(int)*n);
    for ( int i = 2; i < n; i++ )
    {
        if ( !nonPrime[i] )
            prime[count++] = i;
        for ( int j = 0; j < count; j++ )
        {
            if ( i * prime[j] >= n )
                break;
            nonPrime[i*prime[j]] = 1;
            if ( i % prime[j] == 0 )
                break;
        }
    }
    free(nonPrime);
    free(prime);
    return count;
}

int main()
{
    return 0;
}
