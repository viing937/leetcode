#include <stdio.h>

int removeElement(int* nums, int numsSize, int val)
{
    int read, write;
    write = 0;
    for ( read = 0; read < numsSize; read++ )
        if ( nums[read] != val )
            nums[write++] = nums[read];
    return write;
}

int main()
{
    return 0;
}
