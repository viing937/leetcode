#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    set<vector<int>> result;

    void dfs(const vector<int> &nums, int k, vector<int> seq) {
        if (k >= nums.size()) {
            if (seq.size() >= 2)
                result.insert(seq);
            return;
        }
        if (seq.size() == 0 || nums[k] >= seq.back()) {
            seq.push_back(nums[k]);
            dfs(nums, k+1, seq);
            seq.pop_back();
        }
        dfs(nums, k+1, seq);
        return;
    }
public:
    vector<vector<int>> findSubsequences(vector<int> &nums) {
        result.clear();
        dfs(nums, 0, vector<int>());
        return vector<vector<int>>(result.begin(), result.end());
    }
};

int main() {
    vector<int> nums = {4, 6, 7, 7};
    Solution solution;
    solution.findSubsequences(nums);
    return 0;
}
