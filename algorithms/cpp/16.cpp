#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int result = nums[0]+nums[1]+nums[2];
        sort(nums.begin(), nums.end());
        for ( int i = 0; i < (int)nums.size()-2; i++ )
        {
            int j = i+1, k = nums.size()-1;
            while ( j < k )
            {
                int sum = nums[i]+nums[j]+nums[k];
                if ( sum == target )
                    return target;
                result = abs(result-target)>abs(sum-target) ? sum : result;
                if ( sum < target )
                    j++;
                else
                    k--;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
