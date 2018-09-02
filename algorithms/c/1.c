#include <stdio.h>
#include <stdlib.h>

struct Num
{
    int num;
    int index;
};

int cmp(const void *a, const void *b)
{
    return (*(struct Num *)a).num - (*(struct Num *)b).num;
};

int* twoSum(int* nums, int numsSize, int target) {
    int i, j;
    int *ans = (int *)malloc(sizeof(int)*2);
    struct Num *newnums = (struct Num *)malloc(sizeof(struct Num)*numsSize);
    for ( i = 0; i < numsSize; i++ )
    {
        newnums[i].num = nums[i];
        newnums[i].index = i+1;
    }
    qsort(newnums, numsSize, sizeof(newnums[0]), cmp);
    for ( i = 0; i < numsSize-1; i++ )
    {
        for ( j = i+1; j < numsSize; j++ )
        {
            if ( newnums[i].num+newnums[j].num == target )
            {
                ans[0] = newnums[i].index<newnums[j].index ? newnums[i].index : newnums[j].index;
                ans[1] = newnums[i].index<newnums[j].index ? newnums[j].index : newnums[i].index;
                break;
            }
            if ( newnums[i].num+newnums[j].num > target )
                break;
        }
    }
    free(newnums);
    return ans;
}

int main()
{
    int nums[] = {2, 7, 11, 15};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int target = 9;
    int *ans = twoSum(nums, numsSize, target);
    printf("index1=%d, index2=%d\n", ans[0], ans[1]);
    free(ans);
    return 0;
}
