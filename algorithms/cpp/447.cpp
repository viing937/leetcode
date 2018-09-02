#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int calDis(const pair<int, int> &a, const pair<int, int> &b) {
        int dx = a.first-b.first, dy = a.second-b.second;
        return dx*dx+dy*dy;
    }
public:
    int numberOfBoomerangs(vector<pair<int, int>> &points) {
        int result = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < points.size(); i++) {
            m.clear();
            for (int j = 0; j < points.size(); j++) {
                if (i == j)
                    continue;
                m[calDis(points[i], points[j])] += 1;
            }
            for (auto p: m) {
                int cnt = p.second;
                result += cnt*(cnt-1);
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
