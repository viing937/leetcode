#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string ans;
        if ( strs.empty() )
            return ans;
        for ( unsigned int i = 0; i < strs[0].size(); i++ )
        {
            for ( unsigned int j = 1; j < strs.size(); j++ )
                if ( strs[j][i] != strs[0][i] )
                    return ans;
            ans += strs[0][i];
        }
        return ans;
    }
};

int main()
{
    vector<string> strs;
    //strs.push_back("abcdefg");
    //strs.push_back("abcefg");
    //strs.push_back("acdefg");
    Solution solution;
    cout << solution.longestCommonPrefix(strs) << endl;
    return 0;
}
