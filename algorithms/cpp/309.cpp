#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<int> pro(2, 0);
        for ( int i = 1; i < n; ++i )
        {
            int t = pro[0];
            pro[0] = max(pro[0]+prices[i]-prices[i-1], pro[1]);
            pro[1] = max(t, pro[1]);
        }
        return max(pro[0], pro[1]);
    }
};

int main()
{
    vector<int> prices = {6, 1, 3, 2, 4, 7};
    Solution solution;
    cout << solution.maxProfit(prices) << endl;
    return 0;
}
