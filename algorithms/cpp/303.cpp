#include <iostream>
#include <vector>
using namespace std;

class NumArray
{
private:
    vector<int> partial_sum;
public:
    NumArray(vector<int> &nums)
    {
        if ( nums.size() == 0 )
            return;
        int n = nums.size();
        partial_sum.push_back(nums[0]);
        for ( int i = 1; i < n; ++i )
            partial_sum.push_back(partial_sum.back()+nums[i]);
    }
    int sumRange(int i, int j)
    {
        if ( i == 0 )
            return partial_sum[j];
        else
            return partial_sum[j]-partial_sum[i-1];
    }
};

int main()
{
    return 0;
}
