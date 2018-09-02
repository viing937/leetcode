#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
        int m = M.size(), n = M[0].size();
        vector<vector<int>> smoothed(m, vector<int>(n));
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                int count = 0;
                smoothed[x][y] = 0;
                for (auto dx: {-1, 0, 1}) {
                    for (auto dy: {-1, 0, 1}) {
                        if (x+dx >= 0 && x+dx < m && y+dy >= 0 && y+dy < n) {
                            count += 1;
                            smoothed[x][y] += M[x+dx][y+dy];
                        }
                    }
                }
                smoothed[x][y] = floor((double)smoothed[x][y] / count);
            }
        }
        return smoothed;
    }
};

int main() {
    return 0;
}
