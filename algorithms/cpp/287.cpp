#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        int slow = nums.size()-1, fast = slow;
        while ( true )
        {
            slow = nums[slow]-1;
            fast = nums[nums[fast]-1]-1;
            if ( slow == fast )
                break;
        }
        fast = nums.size()-1;
        while ( true )
        {
            slow = nums[slow]-1;
            fast = nums[fast]-1;
            if ( slow == fast )
                return slow+1;
        }
    }
};

int main()
{
    return 0;
}
