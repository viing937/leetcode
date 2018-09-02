#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector< vector<int> > threeSum(vector<int>& nums)
    {
        vector< vector<int> > result;
        vector<int> ans(3);
        map<int, int> counter;
        for ( unsigned int i = 0; i < nums.size(); ++i )
            counter[nums[i]]++;
        for ( auto iIt = counter.begin(); iIt != counter.end(); ++iIt )
        {
            if ( iIt->first > 0 )
                break;
            iIt->second -= 1;
            for ( auto jIt = iIt; jIt != counter.end(); ++jIt )
            {
                if ( jIt->second <= 0 )
                    continue;
                jIt->second -= 1;
                auto kIt = counter.find(-(iIt->first + jIt->first));
                if ( kIt != counter.end() && kIt->first >= jIt->first && kIt->second > 0 )
                {
                    ans[0] = iIt->first, ans[1] = jIt->first, ans[2] = kIt->first;
                    result.push_back(ans);
                }
                jIt->second += 1;
            }
            iIt->second += 1;
        }
        return result;
    }
};

int main()
{
    return 0;
}
