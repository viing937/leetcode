#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) return false;
        int cur, prev;
        bool isForward;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            cur = ((i + nums[i]) % n + n) % n;
            isForward = nums[i] > 0 ? true : false;
            nums[i] = 0;
            while (cur < n && nums[cur] != 0 && nums[cur] > 0 == isForward) {
                prev = cur;
                cur = ((cur + nums[cur]) % n + n) % n;
                if (nums[cur] == 0)
                    return true;
                nums[prev] = 0;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {-2, 1, -1, -2, -2};
    Solution solution;
    solution.circularArrayLoop(nums);
    return 0;
}
