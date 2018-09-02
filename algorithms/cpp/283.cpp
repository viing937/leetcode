#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        unsigned int cnt = 0;
        for ( unsigned int i = 0; i < nums.size(); ++i )
            if ( nums[i] != 0 )
                nums[cnt++] = nums[i];
        while ( cnt < nums.size() )
            nums[cnt++] = 0;
        return;
    }
};

int main()
{
    return 0;
}
