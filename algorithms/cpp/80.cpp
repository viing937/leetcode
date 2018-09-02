#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if ( nums.size() <= 2 )
            return nums.size();
        int newlen = 1;
        bool isduplicate = false;
        for ( unsigned int i = 1; i < nums.size(); ++i )
        {
            if ( nums[i] == nums[i-1] )
            {
                if ( !isduplicate )
                    nums[newlen++] = nums[i];
                isduplicate = true;
            }
            else
            {
                nums[newlen++] = nums[i];
                isduplicate = false;
            }
        }
        return newlen;
    }
};

int main()
{
    return 0;
}
