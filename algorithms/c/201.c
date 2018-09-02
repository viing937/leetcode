#include <stdio.h>

int rangeBitwiseAnd(int m, int n)
{
    int diffBits = 0;
    while ( m != n )
    {
        m >>= 1;
        n >>= 1;
        diffBits += 1;
    }
    return n<<diffBits;
}

int main()
{
    return 0;
}
