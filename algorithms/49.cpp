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
        map< string, vector<int> > mp;
        for ( unsigned int i = 0; i < strs.size(); ++i )
            mp[hashstring(strs[i])].push_back(i);
        vector< vector<string> > result;
        for ( auto it = mp.begin(); it != mp.end(); ++it )
        {
            vector<string> tmp;
            for ( unsigned int i = 0; i < (it->second).size(); ++i )
                tmp.push_back(strs[(it->second)[i]]);
            sort(tmp.begin(), tmp.end());
            result.push_back(tmp);
        }
        return result;
    }
};

int main()
{
    return 0;
}
