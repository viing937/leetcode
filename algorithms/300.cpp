#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> tails;
        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(tails.begin(), tails.end(), nums[i]);
            if (it == tails.end())
                tails.push_back(nums[i]);
            else if (*it > nums[i])
                *it = nums[i];
        }
        return tails.size();
    }
};

int main() {
    return 0;
}
