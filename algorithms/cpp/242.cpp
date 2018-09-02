#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if ( s.size() != t.size() )
            return false;
        map<char, int> ss, tt;
        for ( unsigned int i = 0; i < s.size(); ++i )
            ss[s[i]]++, tt[t[i]]++;
        return ss == tt;
    }
};

int main()
{
    return 0;
}
