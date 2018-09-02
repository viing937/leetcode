#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int length = nums.size();
        vector<int> result(length, 1);
        for ( int i = 1, tmp = 1; i < length; i++ )
        {
            tmp *= nums[i-1];
            result[i] *= tmp;
        }
        for ( int i = length-2, tmp = 1; i >= 0; i-- )
        {
            tmp *= nums[i+1];
            result[i] *= tmp;
        }
        return result;
    }
};

int main()
{
    return 0;
}
