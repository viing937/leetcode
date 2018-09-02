#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution
{
private:
    string convert(int num1, int num2 )
    {
        stringstream ss;
        if ( num1 == num2 )
            ss << num1;
        else
            ss << num1 << "->" << num2;
        return ss.str();
    }
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> result;
        if ( nums.size() == 0 )
            return result;
        int l = 0, r = 0;
        for ( int i = 1; i < (int)nums.size(); i++ )
        {
            if ( nums[i] != nums[r]+1 )
            {
                result.push_back(convert(nums[l], nums[r]));
                l = r = i;
            }
            else
                r = i;
        }
        result.push_back(convert(nums[l], nums[r]));
        return result;
    }
};

int main()
{
    return 0;
}
