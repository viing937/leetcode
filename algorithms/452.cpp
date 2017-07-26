#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>> &points) {
        int n = points.size();
        if (n == 0) return 0;
        sort(points.begin(), points.end());
        int result = 0, right = points[0].second;
        for (int i = 1; i < n; i++) {
            if (points[i].first <= right)
                right = min(right, points[i].second);
            else {
                result += 1;
                right = points[i].second;
            }
        }
        return result+1;
    }
};

int main() {
    return 0;
}
