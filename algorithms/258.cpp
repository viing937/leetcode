#include <iostream>
using namespace std;

class Solution
{
public:
    int addDigits(int num)
    {
        while ( num > 9 )
        {
            int newnum = 0;
            while ( num )
            {
                newnum += num%10;
                num /= 10;
            }
            num = newnum;
        }
        return num;
    }
};

int main()
{
    return 0;
}
