#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int result = 0;
        for (int i = 0, j = 1; j < n; i++) {
            if (i == j)
                j += 1;
            while (j < n && nums[j] - nums[i] < k)
                j += 1;
            while (j+1 < n && nums[j] == nums[j+1])
                j += 1;
            if (j < n && nums[j] - nums[i] == k) {
                result += 1;
                j += 1;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
