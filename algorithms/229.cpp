#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int a = 0, cnta = 0, b = 1, cntb = 0;
        for ( unsigned int i = 0; i < nums.size(); ++i )
        {
            if ( a == nums[i] )
                cnta += 1;
            else if ( b == nums[i] )
                cntb += 1;
            else if ( cnta == 0 )
                a = nums[i], cnta = 1;
            else if ( cntb == 0 )
                b = nums[i], cntb = 1;
            else
                cnta -= 1, cntb -= 1;
        }
        cnta = cntb = 0;
        for ( unsigned int i = 0; i < nums.size(); ++i )
        {
            if ( a == nums[i] ) cnta += 1;
            if ( b == nums[i] ) cntb += 1;
        }
        vector<int> result;
        if ( cnta > (int)nums.size()/3 ) result.push_back(a);
        if ( cntb > (int)nums.size()/3 ) result.push_back(b);
        return result;
    }
};

int main()
{
    return 0;
}
