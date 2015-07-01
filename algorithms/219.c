#include <stdio.h>
#include <stdbool.h>

bool containsNearbyDuplicate(int* nums, int numsSize, int k)
{
    for ( int i = 0; i < numsSize; i++ )
        for ( int j = 1; j <= k && i+j < numsSize; j++ )
            if ( nums[i] == nums[i+j] )
                return true;
    return false;
}

int main()
{
    return 0;
}
