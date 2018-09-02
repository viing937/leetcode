#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        if ( nums.size() <= 0 )
            return 0;
        int start = 0;
        int sum = 0;
        int minlen = nums.size()+5;
        for ( int i = 0; i < (int)nums.size(); i++ )
        {
            sum += nums[i];
            while ( start <= i && sum-nums[start] >= s )
                sum -= nums[start++];
            if ( sum >= s )
                minlen = min(minlen, i-start+1);
        }
        if ( minlen > (int)nums.size() )
            return 0;
        else
            return minlen;
    }
};

int main()
{
    Solution solution;
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> a(arr, arr+sizeof(arr)/sizeof(arr[0]));
    cout << solution.minSubArrayLen(11, a) << endl;
    return 0;
}
