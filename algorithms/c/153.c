#include <stdio.h>

int binary(int l, int r, int arr[])
{
    if ( l == r || arr[l] < arr[r] )
        return l;
    int m = (l+r)>>1;
    if ( arr[m]<arr[l] && arr[m]<=arr[r] )
        return binary(l, m, arr);
    else
        return binary(m+1, r, arr);
}

int findMin(int* nums, int numsSize)
{
    return nums[binary(0, numsSize-1, nums)];
}

int main()
{
    int arr[] = {279,284,285,287,288,296,2,8,10,11,12,13,14,19,20,22,25,26,27,28,29,33,37,39,42,43,47,48,49,50,57,62,63,66,68,69,71,73,74,77,78,79,85,89,92,94,99,111,113,117,120,122,125,134,145,152,155,157,160,161,167,168,181,182,188,189,190,194,199,201,204,208,213,220,223,225,226,227,231,237,240,242,247,254,259,260,261,264,267,271,275};
    printf("%d\n", findMin(arr, sizeof(arr)/sizeof(arr[0])));
    return 0;
}
