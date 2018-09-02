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
        {
            result.push_back(combination);
            return;
        }
        for ( unsigned int i = index; i < candidates.size() && target >= candidates[i]; i++ )
        {
            combination.push_back(candidates[i]);
            dfs(result, combination, candidates, i, target-candidates[i]);
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
        return result;
    }
};

int main()
{
    return 0;
}
