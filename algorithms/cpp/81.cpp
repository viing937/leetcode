#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool search(vector<int>& nums, int target)
    {
        int l = 0, r = nums.size()-1;
        while ( l <= r )
        {
            while ( l < r && nums[l] == nums[l+1] ) l += 1;
            while ( l < r && nums[r] == nums[r-1] ) r -= 1;
            int m = (l+r)/2;
            if ( nums[m] == target ) return true;
            else if ( target < nums[m] )
            {
                if ( nums[l] <= target || nums[m] < nums[l] )
                    r = m-1;
                else
                    l = m+1;
            }
            else
            {
                if ( nums[l] > target || nums[m] >= nums[l] )
                    l = m+1;
                else
                    r = m-1;
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}
