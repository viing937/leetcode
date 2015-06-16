#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int rob(vector<int>& nums)
    {
        if ( nums.empty() )
            return 0;
        if ( nums.size() < 2 )
            return nums[0];
        int p = 0, q = nums[0], r = nums[1], t;
        for ( unsigned int i = 2; i < nums.size(); i++ )
        {
            t = (p>q?p:q)+nums[i];
            p = q;
            q = r;
            r = t;
        }
        return q>r ? q : r;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    Solution solution;
    cout << solution.rob(nums) << endl;
    return 0;
}
