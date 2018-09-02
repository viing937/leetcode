#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int ans = 0;
        for ( unsigned int i = 1; i < prices.size(); i++ )
            if ( prices[i]-prices[i-1] > 0 )
                ans += prices[i]-prices[i-1];
        return ans;
    }
};

int main()
{
    int arr[] = {7,5,3,4,5,6};
    vector<int> prices(arr, arr+sizeof(arr)/sizeof(arr[0]));
    Solution solution;
    cout << solution.maxProfit(prices) << endl;
    return 0;
}
