#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int>& nums)
    {
        int n = nums.size();
        int k = n*(n+1)/2;
        for ( int i = 0; i < n; ++i )
            k -= nums[i];
        return k;
    }
};

int main()
{
    return 0;
}
