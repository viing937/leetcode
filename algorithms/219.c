#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node
{
    int val;
    struct Node *next;
};

struct Set
{
    int bucketSize;
    struct Node **table;
};

void initSet(struct Set *set, int bucketSize)
{
    set->bucketSize = bucketSize;
    set->table = (struct Node **)malloc(sizeof(struct Node *) * bucketSize);
    memset(set->table, 0, sizeof(struct Node *) * bucketSize);
}

bool addValue(struct Set *set, int val)
{
    int idx = val > 0 ? val : -val;
    idx %= set->bucketSize;
    struct Node *ptr = set->table[idx];
    while ( ptr != NULL )
    {
        if ( ptr->val == val )
            return false;
        ptr = ptr->next;
    }
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->val = val;
    ptr->next = set->table[idx];
    set->table[idx] = ptr;
    return true;
}

void releaseSet(struct Set *set)
{
    struct Node *ptr, *tmp;
    for ( int i = 0; i < set->bucketSize; i++ )
    {
        ptr = set->table[i];
        while ( ptr != NULL )
        {
            tmp = ptr;
            ptr = ptr->next;
            free(tmp);
        }
    }
    free(set->table);
    set->table = NULL;
    set->bucketSize = 0;
}

void removeVal(struct Set *set, int val)
{
    struct Node *prevnode = NULL;
    int idx = val > 0 ? val : -val;
    idx %= set->bucketSize;

    struct Node *ptr = set->table[idx];
    while ( ptr )
    {
        if ( ptr->val != val )
        {
            prevnode = ptr;
            ptr = ptr->next;
        }
        else if ( prevnode == NULL )
        {
            set->table[idx] = ptr->next;
            free(ptr);
            break;
        }
        else
        {
            prevnode->next = ptr->next;
            free(ptr);
            break;
        }
    }
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k)
{
    if ( numsSize < 2 )
        return false;
    struct Set set;
    initSet(&set, numsSize);
    for ( int i = 0; i < numsSize; i++ )
    {
        if ( i > k )
            removeVal(&set, nums[i-k-1]);
        if ( !addValue(&set, nums[i]) )
        {
            releaseSet(&set);
            return true;
        }
    }
    releaseSet(&set);
    return false;
}

int main()
{
    return 0;
}
