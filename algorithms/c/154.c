#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int min(int a, int b)
{
    return a<b ? a : b;
}

int binary(int l, int r, int arr[])
{
    if ( l >= r )
        return arr[l];
    if ( r-l == 1 && arr[l]==arr[r] )
        return arr[l];
    int m = (l+r)>>1;
    if ( arr[m] == arr[r] )
    {
        if ( arr[m] != arr[l] )
            return binary(l, m, arr);
        return min(binary(m+1, r, arr), binary(l+1, m-1, arr));
    }
    else if ( arr[m] > arr[r] )
        return binary(m+1, r, arr);
    else
        return binary(l, m, arr);
}

int findMin(int* nums, int numsSize)
{
    if ( numsSize == 0 )
        return 0;
    return binary(0, numsSize-1, nums);
}

int main()
{
    int arr[] = {10,1,10,10,10};
    printf("%d\n", findMin(arr, sizeof(arr)/sizeof(arr[0])));
    return 0;
}
