#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    void gensubsets(vector< vector<int> > &ans, vector<int> &flag, vector<int> &nums)
    {
        if ( flag.size() > nums.size() )
            return;
        vector<int> subset;
        for ( unsigned int i = 0; i < flag.size(); i++ )
            if ( flag[i] )
                subset.push_back(nums[i]);
        if ( ans.empty() || subset != ans.back() )
            ans.push_back(subset);
        flag.push_back(0);
        gensubsets(ans, flag, nums);
        flag.pop_back();
        flag.push_back(1);
        gensubsets(ans, flag, nums);
        flag.pop_back();
        return;
    }
public:
    vector< vector<int> > subsets(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector< vector<int> > ans;
        vector<int> flag;
        gensubsets(ans, flag, nums);
        return ans;
    } 
};

int main()
{
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(0);
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
