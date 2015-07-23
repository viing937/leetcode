#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int cal(vector<int> &nums, int left, int right)
    {
        if ( left >= right )
            return 0;
        if ( left == right-1 )
            return nums[left];
        int p = 0, q = nums[left], r = nums[left+1], t;
        for ( int i = left+2; i < right; i++ )
        {
            t = (p>q?p:q)+nums[i];
            p = q;
            q = r;
            r = t;
        }
        return max(q, r);
    }
public:
    int rob(vector<int>& nums)
    {
        if ( nums.empty() )
            return 0;
        if ( nums.size() < 2 )
            return nums[0];
        return max(nums[0]+cal(nums, 2, nums.size()-1), cal(nums, 1, nums.size()));
    }
};

int main()
{
    return 0;
}
