#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
    // https://en.wikipedia.org/wiki/Lagrange's_four-square_theorem
private:
    bool issquare(int n)
    {
        int t = sqrt(n);
        return t*t == n;
    }
public:
    int numSquares(int n)
    {
        while ( n%4 == 0 )
            n /= 4;
        if ( issquare(n) )
            return 1;
        if ( n%8 == 7 )
            return 4;
        for ( int i = 1; i <= sqrt(n); ++i )
            if ( issquare(n-i*i) )
                return 2;
        return 3;
    }
};

int main()
{
    return 0;
}
