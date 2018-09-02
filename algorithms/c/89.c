#include <stdio.h>
#include <stdlib.h>

int* grayCode(int n, int* returnSize)
{
    *returnSize = 1<<n;
    int *result = (int *)malloc(sizeof(int)*(*returnSize));
    for ( int i = 0; i < *returnSize; i++ )
        result[i] = i^(i>>1);
    return result;
}

int main()
{
    return 0;
}
