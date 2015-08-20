#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    void dfs(vector< vector<int> > &result, vector<int> &tmp, vector<int> &candidates, int target, int start)
    {
        if ( target == 0 )
        {
            result.push_back(tmp);
            return;
        }
        if ( start >= (int)candidates.size() )
        {
            return;
        }
        for ( int i = start; i < (int)candidates.size() && candidates[i] <= target ; ++i )
        {
            tmp.push_back(candidates[i]);
            dfs(result, tmp, candidates, target-candidates[i], i+1);
            tmp.pop_back();
        }
        return;
    }
public:
    vector< vector<int> > combinationSum2(vector<int>& candidates, int target)
    {
        vector< vector<int> > result;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        dfs(result, tmp, candidates, target, 0);
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};

int main()
{
    return 0;
}
