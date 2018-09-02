#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if ( digits == "" )
            return vector<string>();
        char s[][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result(1, "");
        for ( int i = 0; i < (int)digits.size(); i++ )
        {
            int num = digits[i]-'0';
            vector<string> tmp;
            for ( auto it = result.begin(); it != result.end(); it++ )
            {
                for ( int j = 0; s[num][j] != '\0'; j++ )
                    tmp.push_back(*it+s[num][j]);
            }
            result = tmp;
        }
        return result;
    }
};

int main()
{
    return 0;
}
