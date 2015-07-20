#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    void dfs(vector< vector<int> > &result, vector<int> &combination, vector<int> &candidates, int index, int target)
    {
        if ( target == 0 )
            result.push_back(combination);
        else if ( index < (int)candidates.size() && target >= candidates[index] )
        {
            dfs(result, combination, candidates, index+1, target);
            combination.push_back(candidates[index]);
            dfs(result, combination, candidates, index, target-candidates[index]);
            dfs(result, combination, candidates, index+1, target-candidates[index]);
            combination.pop_back();
        }
        return;
    }
public:
    vector< vector<int> > combinationSum(vector<int>& candidates, int target)
    {
        vector< vector<int> > result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        dfs(result, combination, candidates, 0, target);
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};

int main()
{
    return 0;
}
