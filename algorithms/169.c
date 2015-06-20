#include <stdio.h>

int majorityElement(int* nums, int numsSize)
{
    int i;
    int ans, count;
    ans = nums[0], count = 1;
    for ( i = 1; i < numsSize; i++ )
    {
        if ( count == 0 )
            ans = nums[i];
        if ( nums[i] == ans )
            count++;
        else
            count--;
    }
    return ans;
}

int main()
{
    return 0;
}
