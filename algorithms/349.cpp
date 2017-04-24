#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        vector<int> result;

        unordered_map<int, int> cnt;
        for (auto num: nums1)
            cnt[num] += 1;
        for (auto num: nums2) {
            if (cnt[num] > 0) {
                result.push_back(num);
                cnt[num] = 0;
            }
        }

        return result;
    }
};

int main() {
    return 0;
}
