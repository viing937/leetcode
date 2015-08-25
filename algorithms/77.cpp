#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    void dfs(vector< vector<int> > &result, vector<int> &tmp, int n, int k, int begin)
    {
        if ( !k )
        {
            result.push_back(tmp);
            return;
        }
        for ( int i = begin; i <= n; ++i )
        {
            tmp.push_back(i);
            dfs(result, tmp, n, k-1, i+1);
            tmp.pop_back();
        }
        return;
    }
public:
    vector< vector<int> > combine(int n, int k)
    {
        vector< vector<int> > result;
        vector<int> tmp;
        dfs(result, tmp, n, k, 1);
        return result;
    }
};

int main()
{
    return 0;
}
