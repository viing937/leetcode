#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
private:
    bool helper(const vector<int> &nums, int k, vector<int> &state) {
        if (k == nums.size()) {
            bool result = true;
            for (int i = 0; i < state.size(); i++)
                if (state[i] != 0)
                    result = false;
            return true;
        }
        for (int i = 0; i < state.size(); i++) {
            if (state[i] - nums[k] >= 0) {
                state[i] -= nums[k];
                if (helper(nums, k+1, state))
                    return true;
                state[i] += nums[k];
            }
        }
        return false;
    }
public:
    bool makesquare(vector<int> &nums) {
        if (nums.size() < 4)
            return false;
        int side = accumulate(nums.begin(), nums.end(), 0);
        if (side%4)
            return false;
        side /= 4;
        vector<int> state(4, side);
        sort(nums.begin(), nums.end(), greater<int>());
        return helper(nums, 0, state);
    }
};

int main() {
    return 0;
}
