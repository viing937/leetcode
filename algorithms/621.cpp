#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
private:
    struct Comparer{
        bool operator ()(const pair<char, int> &a, const pair<char, int> &b) {
            return a.second < b.second;
        }
    };
public:
    int leastInterval(vector<char> &tasks, int n) {
        unordered_map<char, int> hash;
        for (auto task: tasks)
            hash[task] += 1;
        priority_queue<pair<char, int>, vector<pair<char, int>>, Comparer> q(hash.begin(), hash.end());
        int result = 0;
        while (!q.empty()) {
            int k = n+1;
            vector<pair<char, int>> tmp;
            while (k > 0 && !q.empty()) {
                tmp.push_back(make_pair(q.top().first, q.top().second-1));
                q.pop();
                k -= 1;
                result += 1;
            }
            for (auto p: tmp) {
                if (p.second > 0)
                    q.push(p);
            }
            if (q.empty())
                break;
            result += k;
        }
        return result;
    }
};

int main() {
    return 0;
}
