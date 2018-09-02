#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    const vector<int> dx = {1, -1, 0, 0};
    const vector<int> dy = {0, 0, -1, 1};
    void helper(int x, int y, vector<vector<int>> &g, vector<vector<int>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < dx.size(); i++) {
            int xx = x+dx[i], yy = y+dy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                continue;
            if (g[xx][yy] > 0)
                continue;
            if (matrix[x][y] > matrix[xx][yy])
                continue;
            g[xx][yy] = 1;
            helper(xx, yy, g, matrix);
        }
    }
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>> &matrix) {
        vector<pair<int, int>> result;
        if (matrix.size() == 0)
            return result;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            pacific[0][i] = atlantic[n-1][i] = 1;
            helper(0, i, pacific, matrix);
            helper(n-1, i, atlantic, matrix);
        }
        for (int i = 0; i < n; i++) {
            pacific[i][0] = atlantic[i][m-1] = 1;
            helper(i, 0, pacific, matrix);
            helper(i, m-1, atlantic, matrix);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] > 0 && atlantic[i][j] > 0)
                    result.push_back(make_pair(i, j));
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    Solution solution;
    solution.pacificAtlantic(matrix);
    return 0;
}
