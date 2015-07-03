#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int max_length = 0;
        for ( int i = 0; i < (int)nums.size() && i <= max_length; i++ )
            max_length = max(i+nums[i], max_length);
        return max_length >= (int)nums.size()-1;
    }
};

int main()
{
    return 0;
}
