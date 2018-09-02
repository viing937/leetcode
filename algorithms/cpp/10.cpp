#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector< vector<bool> > dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j-1] == '*')
                {
                    dp[i][j] = dp[i][j] || dp[i][j-2]; // repeat 0 times
                    dp[i][j] = dp[i][j] || (i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]); // repeat at least 1 times
                }
                else
                {
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution solution;
    string a, b;
    cin >> a >> b;
    if (solution.isMatch(a, b))
    {
        cout << a << " matches " << b << endl;
    }
    else
    {
        cout << a << " does not match " << b << endl;
    }
    return 0;
}
