#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    void dfs(vector<int> &nums, vector< vector<int> > &result, vector<int> &per, vector<bool> &visited)
    {
        if ( per.size() == nums.size() )
        {
            result.push_back(per);
            return;
        }
        else
        {
            for ( int i = 0; i < (int)nums.size(); i++ )
            {
                if ( !visited[i] )
                {
                    visited[i] = true;
                    per.push_back(nums[i]);
                    dfs(nums, result, per, visited);
                    per.pop_back();
                    visited[i] = false;
                }
            }
        }
    }
public:
    vector< vector<int> > permute(vector<int>& nums)
    {
        vector< vector<int> > result;
        vector<int> per;
        vector<bool> visited(nums.size(), false);
        dfs(nums, result, per, visited);
        return result;
    }
};

int main()
{
    return 0;
}
