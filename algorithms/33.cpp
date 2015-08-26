#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int l = 0, r = nums.size()-1;
        while ( l <= r )
        {
            int m = (l+r)/2;
            if ( target < nums[m] )
            {
                if ( nums[l] < nums[r] || nums[m] < nums[l] || target > nums[r] )
                    r = m-1;
                else
                    l = m+1;
            }
            else if ( target > nums[m] )
            {
                if ( nums[l] < nums[r] || nums[m] > nums[l] || target < nums[l] )
                    l = m+1;
                else
                    r = m-1;
            }
            else
                return m;
        }
        return -1;
    }
};

int main()
{
    return 0;
}
