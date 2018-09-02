#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    static bool compare(const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
public:
    int maxEnvelopes(vector<pair<int, int>> &envelopes) {
        if (envelopes.size() == 0)
            return 0;
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> tail;
        for (auto envelope: envelopes) {
            int height = envelope.second;
            auto it = lower_bound(tail.begin(), tail.end(), height);
            if (it == tail.end())
                tail.push_back(height);
            else if (*it > height)
                *it = height;
        }
        return tail.size();
    }
};

int main() {
    return 0;
}
