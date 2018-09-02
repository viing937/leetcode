#include <iostream>
using namespace std;

class Solution
{
private:
    bool isAlphanumeric(char ch)
    {
        return (ch >= '0' && ch <= '9')||
               (ch >= 'a' && ch <= 'z')||
               (ch >= 'A' && ch <= 'Z');
    }
    char toLow(char ch)
    {
        if ( ch >= 'A' && ch <= 'Z' )
            return ch-'A'+'a';
        else
            return ch;
    }
public:
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size()-1;
        while ( i < j )
        {
            while ( i < (int)s.size() && !isAlphanumeric(s[i]) )
                i++;
            while ( j >= 0 && !isAlphanumeric(s[j]) )
                j--;
            if ( i < j && toLow(s[i]) != toLow(s[j]) )
                return false;
            i++, j--;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    if ( solution.isPalindrome("race a car") )
        cout << "Yes." << endl;
    else
        cout << "No." << endl;
    return 0;
}
