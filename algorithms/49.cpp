#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector< vector<string> > groupAnagrams(vector<string>& strs)
    {
        sort(strs.begin(), strs.end());
        vector< vector<string> > result;
        unordered_map< string, int > mp;
        for ( unsigned int i = 0; i < strs.size(); ++i )
        {
            string hash = strs[i];
            sort(hash.begin(), hash.end());
            auto it = mp.find(hash);
            if ( it != mp.end() )
                result[it->second].push_back(strs[i]);
            else
            {
                mp[hash] = result.size();
                result.push_back(vector<string>(1, strs[i]));
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
