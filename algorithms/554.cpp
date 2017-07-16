#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>> &wall) {
        unordered_map<int, int> m;
        int count = 0;
        for (int i = 0; i < wall.size(); i++) {
            int s = 0;
            for (int j = 0; j < wall[i].size()-1; j++) {
                s += wall[i][j];
                m[s] += 1;
                count = max(count, m[s]);
            }
        }
        return wall.size()-count;
    }
};

int main() {
    return 0;
}
