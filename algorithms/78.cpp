#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    void gensubsets(vector< vector<int> > &result, vector<int> &subset, vector<int> &nums, int start)
    {
        if ( start >= (int)nums.size() )
            return;
        for ( int i = start; i < (int)nums.size(); ++i )
        {
            subset.push_back(nums[i]);
            result.push_back(subset);
            gensubsets(result, subset, nums, i+1);
            subset.pop_back();
        }
        return;
    }
public:
    vector< vector<int> > subsets(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector< vector<int> > result(1, vector<int>());
        vector<int> subset;
        gensubsets(result, subset, nums, 0);
        return result;
    } 
};

int main()
{
    vector<int> nums = {4, 1, 0};
    Solution solution;
    vector< vector<int> > ans = solution.subsets(nums);
    for ( unsigned int i = 0; i < ans.size(); i++ )
    {
        for ( unsigned int j = 0; j < ans[i].size(); j++ )
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}
