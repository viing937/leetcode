#include <stdio.h>

int singleNumber(int* nums, int numsSize)
{
    int i;
    int ans = 0;
    for ( i = 0; i < numsSize; i++ )
        ans ^= nums[i];
    return ans;
}

int main()
{
    int arr[] = {3,4,5,4,5,3,7,7,2};
    printf("%d\n", singleNumber(arr, sizeof(arr)/sizeof(arr[0])));
    return 0;
}
