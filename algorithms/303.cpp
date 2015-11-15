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
        partial_sum.push_back(0);
        if ( nums.size() == 0 )
            return;
        partial_sum.push_back(nums[0]);
        for ( unsigned int i = 1; i < nums.size(); ++i )
            partial_sum.push_back(partial_sum.back()+nums[i]);
    }
    int sumRange(int i, int j)
    {
        return partial_sum[j+1]-partial_sum[i];
    }
};

int main()
{
    return 0;
}
