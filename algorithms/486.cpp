#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int helper(const vector<int> &nums, int left, int right, int turn) {
        if (left >= right)
            return nums[left] * turn;
        int l = turn*nums[left] + helper(nums, left+1, right, -turn);
        int r = turn*nums[right] + helper(nums, left, right-1, -turn);
        return turn > 0 ? max(l, r) : min(l, r);
    }
public:
    bool PredictTheWinner(vector<int> &nums) {
        return helper(nums, 0, nums.size()-1, 1) >= 0;
    }
};

int main() {
    return 0;
}
