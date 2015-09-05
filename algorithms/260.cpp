#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        int aXorb = 0;
        for ( auto item : nums ) aXorb ^= item;
        int bit = aXorb & (-aXorb);
        int a = 0, b = 0;
        for ( auto item : nums )
        {
            if ( item&bit ) a ^= item;
            else b ^= item;
        }
        return vector<int>{a, b};
    }
};

int main()
{
    return 0;
}
