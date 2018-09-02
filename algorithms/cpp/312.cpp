#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
private:
    int dfs(int l, int r, vector<int> &nums, vector< vector<int> > &D)
    {
        if ( D[l][r] >= 0 )
            return D[l][r];
        D[l][r] = 0;
        for ( int i = l+1; i < r; ++i )
            D[l][r] = max(D[l][r], dfs(l, i, nums, D)+dfs(i, r, nums, D)+nums[l]*nums[i]*nums[r]);
        return D[l][r];
    }
public:
    int maxCoins(vector<int>& nums)
    {
        int n = nums.size();
        vector< vector<int> > D(n+1, vector<int>(n+2, -1));
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        return dfs(0, n+1, nums, D);
    }
};

int main()
{
    return 0;
}
