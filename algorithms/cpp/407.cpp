#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    struct Cell {
        int row;
        int col;
        int height;
        Cell(int row, int col, int height) : row(row), col(col), height(height) {};
    };
    struct Comparer {
        bool operator ()(const Cell &a, const Cell &b) {
            return a.height > b.height;
        }
    };
public:
    int trapRainWater(vector<vector<int>> &heightMap) {
        if (heightMap.size() == 0)
            return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<Cell, vector<Cell>, Comparer> pq;
        for (int i = 0; i < m; i++) {
            visited[i][0] = true;
            pq.push(Cell(i, 0, heightMap[i][0]));
            visited[i][n-1] = true;
            pq.push(Cell(i, n-1, heightMap[i][n-1]));
        }
        for (int i = 0; i < n; i++) {
            visited[0][i] = true;
            pq.push(Cell(0, i, heightMap[0][i]));
            visited[m-1][i] = true;
            pq.push(Cell(m-1, i, heightMap[m-1][i]));
        }
        int result = 0;
        vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
        while (!pq.empty()) {
            Cell cell = pq.top();
            pq.pop();
            for (int i = 0; i < dx.size(); i++) {
                int row = cell.row + dx[i];
                int col = cell.col + dy[i];
                if (row >= 0 && row < m && col >= 0 && col < n && !visited[row][col]) {
                    visited[row][col] = true;
                    result += max(0, cell.height-heightMap[row][col]);
                    heightMap[row][col] = max(heightMap[row][col], cell.height);
                    pq.push(Cell(row, col, heightMap[row][col]));
                }
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
