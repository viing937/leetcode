#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> left;
        for ( unsigned int i = 0; i < s.size(); i++ )
        {
            if ( s[i] == '(' || s[i] == '[' || s[i] == '{' )
                left.push(s[i]);
            else if ( s[i] == ')' || s[i] == ']' || s[i] == '}' )
            {
                if ( !left.empty() )
                {
                    if ( (s[i] == ')' && left.top() == '(') ||
                         (s[i] == ']' && left.top() == '[') ||
                         (s[i] == '}' && left.top() == '{') )
                        left.pop();
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        if ( left.empty() )
            return true;
        else
            return false;
    }
};

int main()
{
    return 0;
}
