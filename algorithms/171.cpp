#include <iostream>
using namespace std;

class Solution
{
public:
    int titleToNumber(string s)
    {
        int ans = 0;
        for ( unsigned int i = 0; i < s.size(); i++ )
            ans = ans*26+s[i]-'A'+1;
        return ans;
    }
};

int main()
{
    Solution solution;
    cout << solution.titleToNumber("AB") << endl;
    return 0;
}
