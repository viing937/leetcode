#include <iostream>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int length = 0;
        int i = s.size()-1;
        while ( i >= 0 && s[i] == ' ' )
            i--;
        while ( i >= 0 && s[i] != ' ' )
        {
            length++;
            i--;
        }
        return length;
    }
};

int main()
{
    Solution solution;
    cout << solution.lengthOfLastWord("World  ") << endl;
    return 0;
}
