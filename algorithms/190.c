#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n)
{
    uint32_t result = 0;
    for ( int i = 0; i < 32; i++ )
        result = (result<<1)|(n>>i&1);
    return result;
}

int main()
{
    printf("%u\n", reverseBits(43261596));
    return 0;
}
