#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    void dfs(vector< vector<int> > &result, vector<int> &tmp, int s, int k, int n)
    {
        if ( k == 0 )
        {
            if ( n == 0 )
                result.push_back(tmp);
            return;
        }
        for ( int i = s; i <= 9; ++i )
        {
            tmp.push_back(i);
            dfs(result, tmp, i+1, k-1, n-i);
            tmp.pop_back();
        }
        return;
    }
public:
    vector< vector<int> > combinationSum3(int k, int n)
    {
        vector< vector<int> > result;
        if ( k > 9 || k <= 0 )
            return result;
        vector<int> tmp;
        dfs(result, tmp, 1, k, n);
        return result;
    }
};

int main()
{
    return 0;
}
