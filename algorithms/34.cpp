#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int binary_left(vector<int> &nums, int left, int right, int target)
    {
        if ( left > right )
            return -1;
        int m = (left+right)/2;
        if ( nums[m] == target && (m==0 || nums[m-1]<target) )
            return m;
        else if ( nums[m] < target )
            return binary_left(nums, m+1, right, target);
        else
            return binary_left(nums, left, m-1, target);
    }
    int binary_right(vector<int> &nums, int left, int right, int target)
    {
        if ( left > right )
            return -1;
        int m = (left+right)/2;
        if ( nums[m] == target && (m==(int)nums.size()-1 || nums[m+1]>target) )
            return m;
        else if ( nums[m] > target )
            return binary_right(nums, left, m-1, target);
        else
            return binary_right(nums, m+1, right, target);
    }
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> range;
        range.push_back(binary_left(nums, 0, nums.size()-1, target));
        range.push_back(binary_right(nums, 0, nums.size()-1, target));
        return range;
    }
};

int main()
{
    return 0;
}
