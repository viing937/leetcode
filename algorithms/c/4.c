#include <stdio.h>
#include <stdlib.h>

double getMedian(int *arr, int n)
{
    if ( n%2 )
        return arr[n/2];
    else
        return (arr[n/2]+arr[n/2-1])/2.0;
}

double merge(int *arr1, int len1, int *arr2, int len2)
{
    int *arr = (int *)malloc(sizeof(int)*(len1+len2));
    int index1 = 0, index2 = 0;
    int index = 0;
    while ( index1 < len1 && index2 < len2 )
    {
        if ( arr1[index1] < arr2[index2] )
            arr[index++] = arr1[index1++];
        else
            arr[index++] = arr2[index2++];
    }
    while ( index1 < len1 )
        arr[index++] = arr1[index1++];
    while ( index2 < len2 )
        arr[index++] = arr2[index2++];
    double result = getMedian(arr, index);
    free(arr);
    return result;
}

double binary(int *arr1, int len1, int *arr2, int len2)
{
    if ( len1 > len2 )
    {
        int *ptmp = arr1;
        arr1 = arr2;
        arr2 = ptmp;
        int tmp = len1;
        len1 = len2;
        len2 = tmp;
    }
    if ( len1 == 1 && len2 == 1 )
        return (arr1[0]+arr2[0])/2.0;
    else if ( len1 == 1 )
    {
        if ( len2%2 )
        {
            if ( arr1[0] <= arr2[len2/2-1] )
                return (arr2[len2/2-1]+arr2[len2/2])/2.0;
            else if ( arr1[0] >= arr2[len2/2+1] )
                return (arr2[len2/2]+arr2[len2/2+1])/2.0;
            else
                return (arr1[0]+arr2[len2/2])/2.0;
        }
        else
        {
            if ( arr1[0] >= arr2[len2/2] )
                return arr2[len2/2];
            else if ( arr1[0] <= arr2[len2/2-1] )
                return arr2[len2/2-1];
            else
                return arr1[0];
        }
    }
    else if ( len1 == 2 )
    {
        return merge(arr1, len1, arr2, len2);
    }
    double m1 = getMedian(arr1, len1);
    double m2 = getMedian(arr2, len2);
    int l = (len1-1)/2;
    if ( m1 == m2 )
        return m1;
    else if ( m1 < m2 )
        return binary(arr1+l, len1-l, arr2, len2-l);
    else
        return binary(arr1, len1-l, arr2+l, len2-l);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    if ( nums1Size == 0 )
        return getMedian(nums2, nums2Size);
    if ( nums2Size == 0 )
        return getMedian(nums1, nums1Size);
    return binary(nums1, nums1Size, nums2, nums2Size);
}

int main()
{
    int a[]={1,2,6,7};
    int b[]={3,4,5,8};
    printf("%lf\n", findMedianSortedArrays(a, sizeof(a)/sizeof(a[0]), b, sizeof(b)/sizeof(b[0])));
    return 0;
}
