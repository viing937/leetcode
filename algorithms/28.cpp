#include <iostream>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        for ( int i = 0; i <= (int)haystack.size()-(int)needle.size(); i++ )
        {
            bool flag = true;
            for ( int j = 0; j < (int)needle.size(); j++ )
            {
                if ( haystack[i+j] != needle[j] )
                {
                    flag = !flag;
                    break;
                }
            }
            if ( flag )
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    cout << solution.strStr("", "") << endl;
    return 0;
}
