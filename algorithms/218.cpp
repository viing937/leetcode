#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings) {
        vector<pair<int, int>> result;
        vector<pair<int, int>> points;
        for (auto building: buildings) {
            points.push_back(make_pair(building[0], -building[2]));
            points.push_back(make_pair(building[1], building[2]));
        }
        sort(points.begin(), points.end());
        multiset<int, greater<int>> heights = {0};
        for (auto point: points) {
            int height = *heights.begin();
            if (point.second < 0)
                heights.insert(-point.second);
            else
                heights.erase(heights.find(point.second));
            if (height != *heights.begin())
                result.push_back(make_pair(point.first, *heights.begin()));
        }
        return result;
    }
};

int main() {
    return 0;
}
