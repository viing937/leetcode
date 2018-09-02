#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    bool ispalindromic(string s)
    {
        int len = s.size();
        for ( int i = 0; i < len/2; ++i )
            if ( s[i] != s[len-1-i] )
                return false;
        return true;
    }
    void dfs(vector< vector<string> > &result, vector<string> &tmp, string s)
    {
        if ( s.size() == 0 )
        {
            result.push_back(tmp);
            return;
        }
        for ( unsigned int i = 0; i < s.size(); ++i )
        {
            if ( ispalindromic(s.substr(0, i+1)) )
            {
                tmp.push_back(s.substr(0, i+1));
                dfs(result, tmp, s.substr(i+1));
                tmp.pop_back();
            }
        }
        return;
    }
public:
    vector< vector<string> > partition(string s)
    {
        vector< vector<string> > result;
        vector<string> tmp;
        if ( s.size() == 0 )
            return result;
        dfs(result, tmp, s);
        return result;
    }
};

int main()
{
    return 0;
}
