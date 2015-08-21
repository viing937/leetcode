#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
private:
    string hashstring(string s)
    {
        sort(s.begin(), s.end());
        return s;
    }
public:
    vector< vector<string> > groupAnagrams(vector<string>& strs)
    {
        map< string, vector<string> > result;
        sort(strs.begin(), strs.end());
        for ( unsigned int i = 0; i < strs.size(); ++i )
            result[hashstring(strs[i])].push_back(strs[i]);
        vector< vector<string> > ans;
        for ( auto it = result.begin(); it != result.end(); ++it )
            ans.push_back(it->second);
        return ans;
    }
};

int main()
{
    return 0;
}
