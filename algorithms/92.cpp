#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x)
    {
        unsigned int k, sign;
        if ( x < 0 )
        {
            k = -x;
            sign = 1;
        }
        else
        {
            k = x;
            sign = 0;
        }
        unsigned int ans = 0;
        while ( k )
        {
            if ( ans > 0x7fffffff/10 )
                return 0;
            ans = ans*10+k%10;
            k /= 10;
        }
        if ( sign )
            return -(int)ans;
        else
            return (int)ans;
    }
};

int main()
{
    int x = -2147483648;
    Solution solution;
    cout << solution.reverse(x) << endl;
    return 0;
}
