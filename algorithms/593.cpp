#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int distance(const pair<int, int> &a, const pair<int, int> &b) {
        return (a.first - b.first) * (a.first - b.first) +
               (a.second - b.second) * (a.second - b.second);
    }
public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4) {
        vector<pair<int, int>> p;
        p.emplace_back(p1[0], p1[1]);
        p.emplace_back(p2[0], p2[1]);
        p.emplace_back(p3[0], p3[1]);
        p.emplace_back(p4[0], p4[1]);
        sort(p.begin(), p.end());
        if (p[0].first == p[3].first && p[0].second == p[3].second)
            return false;
        if ((p[1].first - p[0].first) * (p[3].second - p[2].second) !=
            (p[3].first - p[2].first) * (p[1].second - p[0].second))
            return false;
        if (distance(p[0], p[1]) != distance(p[2], p[3]))
            return false;
        if ((p[3].second - p[0].second) * (p[2].second - p[1].second) !=
            -(p[3].first - p[0].first) * (p[2].first - p[1].first))
            return false;
        if (distance(p[0], p[3]) != distance(p[1], p[2]))
            return false;
        return true;
    }
};

int main() {
    return 0;
}
