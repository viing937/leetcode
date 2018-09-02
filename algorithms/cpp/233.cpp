#include <iostream>
using namespace std;

class Solution
{
public:
    int countDigitOne(int n)
    {
        if ( n <= 0 )
            return 0;
        int j = n, k = 1;
        while ( j >= 10 )
        {
            j /= 10;
            k *= 10;
        }
        if ( j > 1 )
            return k + j*countDigitOne(k-1)+countDigitOne(n%k);
        else
            return n%k+1 + j*countDigitOne(k-1)+countDigitOne(n%k);
    }
};

int main()
{
    return 0;
}
