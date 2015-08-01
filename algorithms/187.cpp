#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        char flag[1048576] = {0};
        vector<string> result;
        int len = s.size(), hash = 0;
        if ( len < 11 )
            return result;
        for ( int i = 0; i < 9; ++i )
            hash = hash<<2 | (s[i]-'A'+1)%5;
        for ( int i = 9; i < len; ++i )
        {
            hash = (hash<<2&0XFFFFF) | (s[i]-'A'+1)%5;
            if ( !flag[hash] )
                flag[hash] = 1;
            else if ( flag[hash] == 1 )
            {
                result.push_back(s.substr(i-9, 10));
                flag[hash] = 2;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
