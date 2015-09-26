#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int trap(vector<int>& height)
    {
        int len = height.size();
        vector<int> left(height.begin(), height.end());
        for ( int i = 1; i < len; ++i )
            left[i] = max(left[i-1], left[i]);
        vector<int> right(height.begin(), height.end());
        for ( int i = len-2; i >= 0; --i )
            right[i] = max(right[i+1], right[i]);
        int result = 0;
        for ( int i = 0; i < len; ++i )
            result += min(left[i], right[i])-height[i];
        return result;
    }
};

int main()
{
    return 0;
}
