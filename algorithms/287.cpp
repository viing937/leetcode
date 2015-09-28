#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        for ( unsigned int i = 1; i < nums.size(); ++i )
            if ( nums[i] == nums[i-1] )
                return nums[i];
    }
};

int main()
{
    return 0;
}
