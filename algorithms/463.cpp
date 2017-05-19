#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        if (grid.size() == 0)
            return 0;
        int n = grid.size(), m = grid[0].size();
        int area = 0, sharing = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0)
                    continue;
                area += 1;
                if (i+1 < n && grid[i+1][j] == 1)
                    sharing += 1;
                if (j+1 < m && grid[i][j+1] == 1)
                    sharing += 1;
            }
        }
        return 4*area-2*sharing;
    }
};

int main() {
    return 0;
}
