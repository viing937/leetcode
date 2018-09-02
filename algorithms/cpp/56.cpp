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
        if (a.start == b.start)
            return a.end < b.end;
        else
            return a.start < b.start;
    }
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        if (intervals.size() == 0)
            return result;
        sort(intervals.begin(), intervals.end(), compare);
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start <= result.back().end)
                result.back().end = max(result.back().end, intervals[i].end);
            else
                result.push_back(intervals[i]);
        }
        return result;
    }
};

int main() {
    return 0;
}
