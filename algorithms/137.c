#include <stdio.h>

int singleNumber(int* nums, int numsSize)
{
    int one, two, three;
    one = two = three = 0;
    for ( int i = 0; i < numsSize; i++ )
    {
        three = two&nums[i];
        two = ((one&nums[i])|two)&(~three);
        one = (nums[i]|one)&(~three);
    }
    return one;
}

int main()
{
    return 0;
}
