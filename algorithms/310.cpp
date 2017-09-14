#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
private:
    int helper(int root, int dir, vector<vector<int>> &g, unordered_map<int, unordered_map<int, int>> &m) {
        if (m[root].find(dir) != m[root].end()) return m[root][dir];
        int result = 0;
        for (auto d: g[dir]) {
            if (d == root) continue;
            result = max(result, helper(dir, d, g, m));
        }
        m[root][dir] = result + 1;
        return result + 1;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges) {
        vector<vector<int>> g(n);
        for (int i = 0; i < edges.size(); i++) {
            g[edges[i].first].push_back(edges[i].second);
            g[edges[i].second].push_back(edges[i].first);
        }
        unordered_map<int, unordered_map<int, int>> m;
        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            heights[i] = 0;
            for (auto d: g[i])
                heights[i] = max(heights[i], helper(i, d, g, m));
        }
        int minHeight = *min_element(heights.begin(), heights.end());
        vector<int> result;
        for (int i = 0; i < n; i++)
            if (heights[i] == minHeight)
                result.push_back(i);
        return result;
    }
};

int main() {
    return 0;
}
