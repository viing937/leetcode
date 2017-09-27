#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int find(int x, vector<int> &pre) {
        int r = x;
        while (pre[r] != 0)
            r = pre[r];
        int i = x, j;
        while (pre[i] != 0) {
            j = pre[i];
            pre[i] = r;
            i = j;
        }
        return r;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = edges.size();
        vector<int> pre(n+1, 0);
        for (int i = 0; i < edges.size(); i++) {
            int fx = find(edges[i][0], pre), fy = find(edges[i][1], pre);
            if (fx == fy) return edges[i];
            pre[fx] = fy;
        }
    }
};

int main() {
    return 0;
}
