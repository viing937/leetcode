#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

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
    int *newnums = (int *)malloc(sizeof(int)*numsSize);
    memcpy(newnums, nums, sizeof(int)*numsSize);
    int index = 1;
    for ( int i = 1; i < numsSize; i++ )
        if ( newnums[index-1] != newnums[i] )
            newnums[index++] = newnums[i];
    int result = newnums[binary(0, index-1, newnums)];
    free(newnums);
    return result;
}

int main()
{
    int arr[] = {10,1,10,10,10};
    printf("%d\n", findMin(arr, sizeof(arr)/sizeof(arr[0])));
    return 0;
}
