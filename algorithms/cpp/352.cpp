#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

inline bool operator <(const Interval &a, const Interval &b) {
    return a.start < b.start || a.start == b.start && a.end < b.end;
}

class SummaryRanges {
private:
    set<Interval> interval;
    unordered_map<int, bool> isExist;
    unordered_map<int, Interval> leftBound, rightBound;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
    }

    void addNum(int val) {
        if (isExist[val]) return;
        isExist[val] = true;
        int left = val, right = val;
        if (leftBound.find(val+1) != leftBound.end()) {
            right = leftBound[val+1].end;
            interval.erase(leftBound[val+1]);
            leftBound.erase(val+1);
            rightBound.erase(right);
        }
        if (rightBound.find(val-1) != rightBound.end()) {
            left = rightBound[val-1].start;
            interval.erase(rightBound[val-1]);
            leftBound.erase(left);
            rightBound.erase(val-1);
        }
        Interval i = Interval(left, right);
        interval.insert(i);
        leftBound[left] = i;
        rightBound[right] = i;
        return;
    }

    vector<Interval> getIntervals() {
        return vector<Interval>(interval.begin(), interval.end());
    }
};

int main() {
    return 0;
}
