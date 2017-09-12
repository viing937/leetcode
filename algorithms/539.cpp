#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string> &timePoints) {
        int n = timePoints.size();
        vector<int> mins(n);
        for (int i = 0; i < n; i++) {
            const auto &time = timePoints[i];
            mins[i] = 60*stoi(time.substr(0, 2)) + stoi(time.substr(3));
        }
        sort(mins.begin(), mins.end());
        int result = min(mins[n-1]-mins[0], 1440+mins[0]-mins[n-1]);
        for (int i = 1; i < n; i++)
            result = min(result, mins[i]-mins[i-1]);
        return result;
    }
};

int main() {
    return 0;
}
