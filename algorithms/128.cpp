#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> s;
        for ( unsigned int i = 0; i < nums.size(); ++i )
            s.insert(nums[i]);
        int result = 0;
        for ( unsigned int i = 0; i < nums.size(); ++i )
        {
            int count = 1;
            s.erase(nums[i]);
            for ( int num = nums[i]-1; s.find(num) != s.end(); --num )
            {
                count += 1;
                s.erase(num);
            }
            for ( int num = nums[i]+1; s.find(num) != s.end(); ++num )
            {
                count += 1;
                s.erase(num);
            }
            result = max(result, count);
        }
        return result;
    }
};

int main()
{
    return 0;
}
