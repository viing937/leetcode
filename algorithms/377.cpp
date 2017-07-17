#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int, int> m;
    int helper(const vector<int> &nums, int target) {
        if (target <= 0)
            return target == 0 ? 1 : 0;
        if (m.find(target) != m.end())
            return m[target];
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
            result += helper(nums, target-nums[i]);
        m[target] = result;
        return result;
    }
public:
    int combinationSum4(vector<int> &nums, int target) {
        m.clear();
        return helper(nums, target);
    }
};

int main() {
    return 0;
}
