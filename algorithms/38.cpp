#include <iostream>
#include <sstream>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string a("1");
        for ( int i = 1; i < n; i++ )
        {
            stringstream ss;
            char ch = a[0];
            int cnt = 1;
            for ( unsigned int j = 1; j < a.size(); j++ )
            {
                if ( a[j] == ch )
                    cnt++;
                else
                {
                    ss << cnt << ch;
                    ch = a[j];
                    cnt = 1;
                }
            }
            ss << cnt << ch;
            a = ss.str();
        }
        return a;
    }
};

int main()
{
    Solution solution;
    cout << solution.countAndSay(6) << endl;
    return 0;
}
