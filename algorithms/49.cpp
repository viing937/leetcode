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
        sort(strs.begin(), strs.end());
        map< string, vector<int> > mp;
        for ( unsigned int i = 0; i < strs.size(); ++i )
            mp[hashstring(strs[i])].push_back(i);
        vector< vector<string> > result;
        for ( auto it = mp.begin(); it != mp.end(); ++it )
        {
            result.push_back(vector<string>());
            for ( unsigned int i = 0; i < (it->second).size(); ++i )
                result.back().push_back(strs[(it->second)[i]]);
        }
        return result;
    }
};

int main()
{
    return 0;
}
