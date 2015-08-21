#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
private:
    map<char, int> hashstring(string &s)
    {
        map<char, int> hash;
        int len = s.size();
        for ( int i = 0; i < len; ++i )
            hash[s[i]] += 1;
        return hash;
    }
public:
    vector< vector<string> > groupAnagrams(vector<string>& strs)
    {
        map< map<char, int>, vector<string> > result;
        int len = strs.size();
        for ( int i = 0; i < len; ++i )
            result[hashstring(strs[i])].push_back(strs[i]);
        vector< vector<string> > ans;
        for ( auto it = result.begin(); it != result.end(); ++it )
        {
            sort((it->second).begin(), (it->second).end());
            ans.push_back(it->second);
        }
        return ans;
    }
};

int main()
{
    return 0;
}
