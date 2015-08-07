#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> minproduct(n), maxproduct(n);
        minproduct[0] = maxproduct[0] = nums[0];
        for ( int i = 1; i < n; ++i )
        {
            vector<int> tmp(3);
            tmp[0] = nums[i];
            tmp[1] = nums[i]*minproduct[i-1];
            tmp[2] = nums[i]*maxproduct[i-1];
            sort(tmp.begin(), tmp.end());
            minproduct[i] = tmp[0];
            maxproduct[i] = tmp[2];
        }
        return *max_element(maxproduct.begin(), maxproduct.end());
    }
};

int main()
{
    return 0;
}
