#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<int> findRightInterval(vector<Interval> &intervals) {
        int n = intervals.size();
        map<int, int> startToIndex;
        for (int i = 0; i < n; i++)
            startToIndex[intervals[i].start] = i;
        vector<int> result(n, -1);
        for (int i = 0; i < n; i++) {
            auto it = startToIndex.lower_bound(intervals[i].end);
            if (it != startToIndex.end())
                result[i] = it->second;
        }
        return result;
    }
};

int main() {
    return 0;
}
