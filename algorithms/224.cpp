#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int evaluate(string &s, unsigned int &pos)
    {
        int result = 0;
        bool neg = false;
        while ( pos < s.size() && s[pos] != ')' )
        {
            if ( s[pos] == '+' || s[pos] == ' ' )
            {
                pos += 1;
            }
            else if ( s[pos] == '-' )
            {
                pos += 1;
                neg = !neg;
            }
            else if ( s[pos] == '(' )
            {
                pos += 1;
                result += neg ? -evaluate(s, pos) : evaluate(s, pos);
                neg = false;
            }
            else
            {
                int num = 0;
                while ( pos < s.size() && isdigit(s[pos]))
                    num = num*10+s[pos++]-'0';
                result += neg ? -num : num;
                neg = false;
            }
        }
        pos += 1;
        return result;
    }
public:
    int calculate(string s)
    {
        unsigned int pos = 0;
        return evaluate(s, pos);
    }
};

int main()
{
    return 0;
}
