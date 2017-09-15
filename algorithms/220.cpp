#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (k < 1 || t < 0) return false;
        unordered_map<long, long> m;
        for (int i = 0; i < nums.size(); i++) {
            long remappedNum = (long)nums[i] - INT32_MIN;
            long bucket = remappedNum / ((long)t + 1);
            if (m.find(bucket) != m.end() ||
                m.find(bucket-1) != m.end() && remappedNum-m[bucket-1] <= t ||
                m.find(bucket+1) != m.end() && m[bucket+1]-remappedNum <= t)
                return true;
            if (i-k >= 0) {
                long lastBucket = ((long)nums[i-k]-INT32_MIN) / ((long)t + 1);
                m.erase(lastBucket);
            }
            m[bucket] = remappedNum;
        }
        return false;
    }
};

int main() {
    return 0;
}
