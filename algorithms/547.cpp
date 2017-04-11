#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>> &M) {
        int n = M.size();
        vector<bool> visited(n, false);

        int result = 0;
        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;
            result += 1;

            s.push(i);
            while (!s.empty()) {
                int t = s.top(); s.pop();
                visited[t] = true;
                for (int j = 0; j < n; j++)
                    if (M[t][j] && !visited[j])
                        s.push(j);
            }
        }

        return result;
    }
};

int main() {
    return 0;
}
