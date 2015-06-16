#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        if ( s == "" || s[0] == '0' )
            return 0;
        vector<int> dp;
        dp.push_back(1);
        dp.push_back(1);
        for ( unsigned int i = 1; i < s.size(); i++ )
        {
            int tmp = 0;
            if ( s[i] != '0' )
                tmp += dp[i];
            if ( s[i-1] == '1' || ( s[i-1]=='2' && s[i] >= '0' && s[i] <= '6' ) )
                tmp += dp[i-1];
            dp.push_back(tmp);
        }
        return dp.back();
    }
};

int main()
{
    Solution solution;
    cout << solution.numDecodings("10") << endl;
    return 0;
}
