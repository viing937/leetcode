#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges) {
        if (n == 1) return vector<int>(1, 0);
        vector<unordered_set<int>> g(n);
        for (int i = 0; i < edges.size(); i++) {
            g[edges[i].first].insert(edges[i].second);
            g[edges[i].second].insert(edges[i].first);
        }
        vector<int> leaves;
        for (int i = 0; i < n; i++)
            if (g[i].size() == 1)
                leaves.push_back(i);
        while (n > 2) {
            n -= leaves.size();
            vector<int> newLeaves;
            for (auto i: leaves) {
                int j = *g[i].begin();
                g[j].erase(i);
                if (g[j].size() == 1)
                    newLeaves.push_back(j);
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};

int main() {
    return 0;
}
