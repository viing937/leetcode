#include <stdio.h>

int binary(int l, int r, int target, int arr[])
{
    if ( l >= r )
    {
        if ( target > arr[l] )
            return l+1;
        else
            return l;
    }
    int m = (l+r)>>1;
    if ( target == arr[m] )
        return m;
    else if ( target > arr[m] )
        return binary(m+1, r, target, arr);
    else
        return binary(l, m-1, target, arr);
}

int searchInsert(int* nums, int numsSize, int target)
{
    return binary(0, numsSize-1, target, nums);
}

int main()
{
    int arr[] = {3, 5, 7, 9, 10};
    printf("%d\n", searchInsert(arr, sizeof(arr)/sizeof(arr[0]), 8));
    return 0;
}
