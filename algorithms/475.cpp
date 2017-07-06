#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        int n = houses.size(), m = heaters.size();
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int result = INT_MIN;
        int index = 0;
        for (int i = 0; i < n; i++) {
            while (index+1 < m && abs(houses[i]-heaters[index+1]) <= abs(houses[i]-heaters[index]))
                index += 1;
            result = max(result, abs(houses[i]-heaters[index]));
        }
        return result;
    }
};

int main() {
    vector<int> houses = {1, 2, 3};
    vector<int> heaters = {1, 2, 3};
    Solution solution;
    cout << solution.findRadius(houses, heaters) << endl;
    return 0;
}
