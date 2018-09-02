#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<long long> left, right;
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    void addNum(int num) {
        left.push(num);
        right.push(-left.top());
        left.pop();
        if (left.size() < right.size()) {
            left.push(-right.top());
            right.pop();
        }
    }
    double findMedian() {
        return (left.size()==right.size()) ? (left.top()-right.top())/2.0 : left.top();
    }
};

int main() {
    return 0;
}
