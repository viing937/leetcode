#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    vector<int> helper(vector<int> &nums1, vector<int> &nums2) {
        vector<int> result;
        unordered_map<int, int> m;
        for (auto num: nums1)
            m[num] += 1;
        for (auto num: nums2) {
            m[num] -= 1;
            if (m[num] >= 0)
                result.push_back(num);
        }
        return result;
    }
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.size() <= nums2.size())
            return helper(nums1, nums2);
        else
            return helper(nums2, nums1);
    }
};

int main() {
    return 0;
}
