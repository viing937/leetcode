#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> helper(const vector<int> &nums, int k) {
        vector<int> result;
        result.reserve(k);
        int n = nums.size(), idx = 0;
        while (idx < n) {
            while (!result.empty() && result.size()+n-idx > k && nums[idx] > result.back())
                result.pop_back();
            if (result.size() < k)
                result.push_back(nums[idx]);
            idx += 1;
        }
        return result;
    }
    vector<int> merge(const vector<int> &nums1, const vector<int> &nums2) {
        int n = nums1.size(), m = nums2.size(), k = n+m;
        vector<int> result;
        result.reserve(k);
        for (int i = 0, j = 0; result.size() < k; )
            result.push_back(greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++]);
        return result;
    }
    bool greater(const vector<int> &nums1, int i, const vector<int> &nums2, int j) {
        while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j])
            i += 1, j += 1;
        return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
    }
public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<int> result;
        for (int i = max(0, k-m); i <= n && i <= k; i++) {
            vector<int> sub1 = helper(nums1, i);
            vector<int> sub2 = helper(nums2, k-i);
            vector<int> candidate = merge(sub1, sub2);
            if (greater(candidate, 0, result, 0))
                result = candidate;
        }
        return result;
    }
};

int main() {
    vector<int> nums1 = {3, 4, 6, 5}, nums2 = {9, 1, 2, 5, 8, 3};
    Solution solution;
    solution.maxNumber(nums1, nums2, 5);
    return 0;
}
