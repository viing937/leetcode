#include <stdio.h>

int maxSubArray(int* nums, int numsSize)
{
    if ( numsSize == 0 )
        return 0;
    int maxsum, thissum;
    maxsum = nums[0];
    thissum = 0;
    for ( int i = 0; i < numsSize; i++ )
    {
        thissum += nums[i];
        if ( thissum > maxsum )
            maxsum = thissum;
        if ( thissum < 0 )
            thissum = 0;
    }
    return maxsum;
}

int main()
{
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("%d\n", maxSubArray(arr, sizeof(arr)/sizeof(arr[0])));
    return 0;
}
