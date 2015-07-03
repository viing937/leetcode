#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int len = gas.size();
        int tank = 0, start = 0;
        for ( int cur = 0; cur < start+len; cur++ )
        {
            tank += gas[cur%len]-cost[cur%len];
            while ( start < len && tank < 0 )
            {
                tank -= gas[start]-cost[start];
                start++;
            }
            if ( start == len )
                return -1;
        }
        return start;
    }
};

int main()
{
    int gasarr[] = {2,4}, costarr[] = {3,4};
    vector<int> gas(gasarr, gasarr+sizeof(gasarr)/sizeof(gasarr[0]));
    vector<int> cost(costarr, costarr+sizeof(costarr)/sizeof(costarr[0]));
    Solution solution;
    cout << solution.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
