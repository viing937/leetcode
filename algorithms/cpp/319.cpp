#include <iostream>
using namespace std;

class Solution
{
public:
    int bulbSwitch(int n)
    {
        int result = 0;
        for ( int i = 1; i*i <= n; ++i )
            result += 1;
        return result;
    }
};

int main()
{
    return 0;
}
