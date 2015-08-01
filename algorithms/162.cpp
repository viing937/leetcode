#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int>& nums)
    {
        int l = 0, r = nums.size();
        while ( l+1 < r )
        {
            int m = (l+r)/2;
            if ( m && nums[m] < nums[m-1] )
                r = m;
            else
                l = m;
        }
        return l;
    }
};

int main()
{
    return 0;
}
