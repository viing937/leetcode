#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    void nSum(vector<int> &nums, int n, int target, vector< vector<int> > &result, vector<int> &tmp, int start)
    {
        if ( n == 0 )
        {
            if ( target == 0 )
                result.push_back(tmp);
            return;
        }
        for ( int i = start; i < (int)nums.size(); ++i )
        {
            if ( nums[i]*n > target || nums.back()*n < target )
                break;
            tmp.push_back(nums[i]);
            nSum(nums, n-1, target-nums[i], result, tmp, i+1);
            tmp.pop_back();
            while ( i < (int)nums.size()-n && nums[i] == nums[i+1] )
                i += 1;
        }
        return;
    }
public:
    vector< vector<int> > fourSum(vector<int>& nums, int target)
    {
        vector< vector<int> > result;
        if ( nums.size() < 4 )
            return result;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        nSum(nums, 4, target, result, tmp, 0);
        return result;
    }
};

int main()
{
    return 0;
}
