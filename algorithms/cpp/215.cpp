#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int partition(vector<int> &nums, int l, int r)
    {
        int balance = nums[l];
        int i = l, j = r+1;
        while ( true )
        {
            while ( nums[++i] < balance && i < r );
            while ( nums[--j] > balance );
            if ( i >= j )
                break;
            swap(nums[i], nums[j]);
        }
        nums[l] = nums[j];
        nums[j] = balance;
        return j;
    }
    int select(vector<int> &nums, int l, int r, int k)
    {
        if ( l == r )
            return nums[l];
        int i = partition(nums, l, r), j = i-l+1;
        if ( k == j )
            return nums[i];
        if ( k < j )
            return select(nums, l, i-1, k);
        else
            return select(nums, i+1, r, k-j);
    }
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        k = nums.size()-k+1;
        return select(nums, 0, nums.size()-1, k);
    }
};

int main()
{
    vector<int> a = {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    Solution solution;
    solution.findKthLargest(a, 20);
    return 0;
}
