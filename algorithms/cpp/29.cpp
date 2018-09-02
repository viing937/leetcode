#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if( divisor == 0 || (dividend == INT_MIN && divisor == -1) )
            return INT_MAX;
        bool sign = (dividend<0)==(divisor<0);
        unsigned int a = abs(dividend), b = abs(divisor);
        int ans = 0;
        for ( int i = 31; i >= 0; i-- )
        {
            if ( a>>i >= b )
            {
                ans = (ans<<1)|1;
                a -= (b<<i);
            }
            else
                ans = ans<<1;
        }
        if ( sign )
            return ans;
        else
            return -ans;
    }
};

int main()
{
    Solution solution;
    cout << solution.divide(5, 2) << endl;
    return 0;
}
