#include <iostream>
#include <sstream>
using namespace std;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int a = 0, b = 0;
        int len = secret.size();
        int s_cnt[10] = {0}, g_cnt[10] = {0};
        for ( int i = 0; i < len; ++i )
        {
            if ( secret[i] == guess[i] )
                a += 1;
            else
            {
                s_cnt[secret[i]-'0'] += 1;
                g_cnt[guess[i]-'0'] += 1;
            }
        }
        for ( int i = 0; i < 10; ++i )
            b += min(s_cnt[i], g_cnt[i]);
        stringstream convert;
        convert << a << "A" << b << "B";
        return convert.str();
    }
};

int main()
{
    return 0;
}
