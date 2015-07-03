#include <iostream>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if ( n == 0 )
            return 1;
        if ( n < 0 )
        {
            x = 1/x;
            n = -n;
        }
        double result = myPow(x, n/2);
        if ( n%2 )
            return result*result*x;
        else
            return result*result;
    }
};

int main()
{
    return 0;
}
