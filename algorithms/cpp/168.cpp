#include <iostream>
using namespace std;

class Solution
{
public:
    string convertToTitle(int n)
    {
        if ( n <= 26 )
            return string(1, 'A'+n-1);
        else if ( n%26 == 0 )
            return convertToTitle(n/26-1)+string(1, 'Z');
        else
            return convertToTitle(n/26)+string(1, 'A'+n%26-1);
    }
};

int main()
{
    Solution solution;
    for ( int i = 1; i <= 53; i++ )
        cout << i << "\t" << solution.convertToTitle(i) << endl;
    return 0;
}
