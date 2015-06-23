#include <stdio.h>

int findMin(int* nums, int numsSize)
{
    if ( nums[0] < nums[numsSize-1] )
        return nums[0];
    int result = nums[numsSize-1];
    for ( int i = numsSize-2; i >= 0; i-- )
    {
        if ( nums[i] <= result )
            result = nums[i];
        else
            break;
    }
    return result;
}

int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    printf("%d\n", findMin(arr, sizeof(arr)/sizeof(arr[0])));
    return 0;
}
