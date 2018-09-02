#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    void dfs(vector<string> &result, string ip, string str, int pos)
    {
        if ( pos == 4 && str == "" )
            result.push_back(ip.substr(1));
        else
            for ( int i = 1; i <= (str[0]=='0'?1:3) && i <= (int)str.size(); ++i )
                if ( stoi(str.substr(0, i)) <= 255 )
                    dfs(result, ip+"."+str.substr(0, i), str.substr(i), pos+1);
        return;
    }
public:
    vector<string> restoreIpAddresses(string s)
    {
        if ( s.size() > 12 )
            return vector<string>();
        vector<string> result;
        dfs(result, "", s, 0);
        return result;
    }
};

int main()
{
    Solution solution;
    solution.restoreIpAddresses("0000");
    return 0;
}
