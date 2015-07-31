#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    static bool cmp(const string &a, const string &b)
    {
        if ( a.size() != b.size() )
            return cmp(a+b, b+a);
        else
            return a < b;
    }
public:
    string largestNumber(vector<int>& nums)
    {
        vector<string> strnums(nums.size());
        for ( unsigned int i = 0; i < nums.size(); ++i )
        {
            stringstream ss;
            ss << nums[i];
            strnums[i] = ss.str();
        }
        sort(strnums.begin(), strnums.end(), cmp);
        stringstream result;
        for ( int i = nums.size()-1; i >= 0; --i )
            result << strnums[i];
        if ( result.str()[0] == '0' )
            return "0";
        else
            return result.str();
    }
};

int main()
{
    return 0;
}
