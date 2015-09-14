#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        deque<int> p;
        vector<int> result;
        for ( int i = 0; i < (int)nums.size(); ++i )
        {
            while ( !p.empty() && nums[p.back()] <= nums[i] )
                p.pop_back();
            p.push_back(i);
            if ( p.front() <= i-k )
                p.pop_front();
            if ( i >= k-1 )
                result.push_back(nums[p.front()]);
        }
        return result;
    }
};

int main()
{
    return 0;
}
