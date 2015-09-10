#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    void gensubsets(vector< vector<int> > &result, vector<int> &nums, vector<int> &subset, int start)
    {
        if ( start >= (int)nums.size() )
            return;
        for ( int i = start; i < (int)nums.size(); ++i )
        {
            subset.push_back(nums[i]);
            result.push_back(subset);
            gensubsets(result, nums, subset, i+1);
            subset.pop_back();
            while ( i < (int)nums.size()-1 && nums[i] == nums[i+1] )
                i += 1;
        }
        return;
    }
public:
    vector< vector<int> > subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector< vector<int> > result(1, vector<int>());
        vector<int> subset;
        gensubsets(result, nums, subset, 0);
        return result;
    }
};

int main()
{
    return 0;
}
