#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
private:
    int calSteps(int sx, int sy, int ex, int ey, vector<vector<int>> &forest) {
        int m = forest.size(), n = forest[0].size();
        queue<pair<int, int>> q; q.emplace(sx, sy);
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[sx][sy] = true;
        vector<int> dir = {1, 0, -1, 0, 1};
        int steps = -1;
        while (!q.empty()) {
            steps += 1;
            int qsize = q.size();
            while (qsize--) {
                int curX = q.front().first, curY = q.front().second;
                q.pop();
                if (curX == ex && curY == ey) return steps;
                for (int i = 0; i < 4; i++) {
                    int nextX = curX + dir[i], nextY = curY + dir[i+1];
                    if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue;
                    if (forest[nextX][nextY] <= 1 || visited[nextX][nextY]) continue;
                    visited[nextX][nextY] = true;
                    q.emplace(nextX, nextY);
                }
            }
        }
        return -1;
    }
public:
    int cutOffTree(vector<vector<int>> &forest) {
        int m = forest.size(), n = forest[0].size();
        vector<vector<int>> trees;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (forest[i][j] > 1)
                    trees.push_back({forest[i][j], i, j});
        sort(trees.begin(), trees.end());
        int result = 0;
        for (int i = 0, curX = 0, curY = 0; i < trees.size(); i++) {
            int x = trees[i][1], y = trees[i][2];
            int steps = calSteps(curX, curY, x, y, forest);
            if (steps == -1) return -1;
            result += steps;
            curX = x, curY = y;
        }
        return result;
    }
};

int main() {
    return 0;
}
