#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int> &Profits, vector<int> &Capital) {
        vector<pair<int, int>> tasks;
        for (int i = 0; i < Profits.size(); i++)
            tasks.push_back(make_pair(Capital[i], Profits[i]));
        sort(tasks.begin(), tasks.end());
        priority_queue<int> fit;
        for (int i = 0; i < tasks.size(); i++) {
            if (k == 0)
                break;
            while (W < tasks[i].first && !fit.empty()) {
                k -= 1;
                W += fit.top();
                fit.pop();
            }
            if (W >= tasks[i].first)
                fit.push(tasks[i].second);
            else
                break;
        }
        while (k > 0 && !fit.empty()) {
            k -= 1;
            W += fit.top();
            fit.pop();
        }
        return W;
    }
};

int main() {
    return 0;
}
