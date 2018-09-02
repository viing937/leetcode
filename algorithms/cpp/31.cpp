#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        int k, l;
        for ( k = nums.size()-1; k > 0; k-- )
            if ( nums[k-1] < nums[k] )
                break;
        if ( k <= 0 )
        {
            sort(nums.begin(), nums.end());
            return;
        }
        for ( l = nums.size()-1; nums[l] <= nums[k-1]; l-- )
            ;
        swap(nums[k-1], nums[l]);
        reverse(nums.begin()+k, nums.end());
        return;
    }
};

int main()
{
    return 0;
}
