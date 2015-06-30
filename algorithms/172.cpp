#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int count = 0;
        for ( long long i = 5; n/i; i *= 5 )
            count += n/i;
        return count;
    }
};

int main()
{
    Solution solution;
    //cout << solution.trailingZeroes(1808548329) << endl;
    cout << solution.trailingZeroes(15) << endl;
    return 0;
}
