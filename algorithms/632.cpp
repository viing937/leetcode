#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    struct Element {
        int val;
        int idx;
        int row;
        Element(int val, int idx, int row): val(val), idx(idx), row(row) {}
        bool operator <(const Element &a) const {
            return val > a.val;
        }
    };
public:
    vector<int> smallestRange(vector<vector<int>> &nums) {
        int maxVal = INT_MIN;
        priority_queue<Element> pq;
        for (int i = 0; i < nums.size(); i++) {
            maxVal = max(maxVal, nums[i][0]);
            pq.push(Element(nums[i][0], 0, i));
        }
        int range = INT_MAX;
        vector<int> result(2);
        while (pq.size() == nums.size()) {
            Element e = pq.top();
            pq.pop();
            if (maxVal - e.val < range) {
                range = maxVal - e.val;
                result[0] = e.val;
                result[1] = maxVal;
            }
            if (e.idx+1 < nums[e.row].size()) {
                pq.emplace(nums[e.row][e.idx+1], e.idx+1, e.row);
                maxVal = max(maxVal, nums[e.row][e.idx+1]);
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
