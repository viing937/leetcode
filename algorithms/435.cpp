#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
private:
    static bool compare(const Interval &a, const Interval &b) {
        return a.start < b.start || (a.start == b.start && a.end < b.end);
    }
public:
    int eraseOverlapIntervals(vector<Interval> &intervals) {
        if (intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end(), compare);
        int end = intervals[0].end, cnt = 1;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start >= end) {
                end = intervals[i].end;
                cnt += 1;
            }
            else
                end = min(end, intervals[i].end);
        }
        return intervals.size() - cnt;
    }
};

int main() {
    return 0;
}
