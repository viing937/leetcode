#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        double logResule = log(n)/log(3);
        if ( abs(logResule-(int)(logResule+0.5)) <= 1e-10 )
            return true;
        else
            return false;
    }
};

int main()
{
    Solution solution;
    solution.isPowerOfThree(243);
    return 0;
}
