#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
private:
    static bool compare(const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
    }
public:
    int scheduleCourse(vector<vector<int>> &courses) {
        sort(courses.begin(), courses.end(), compare);
        int s = 0;
        priority_queue<int> q;
        for (auto course: courses) {
            if (s + course[0] <= course[1]) {
                s += course[0];
                q.push(course[0]);
            }
            else if (course[0] < q.top() && s - q.top() + course[0] <= course[1]) {
                s = s - q.top() + course[0];
                q.pop();
                q.push(course[0]);
            }
        }
        return q.size();
    }
};

int main() {
    return 0;
}
