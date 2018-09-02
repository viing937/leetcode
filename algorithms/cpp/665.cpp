#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int> &nums) {
        int cnt = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i-1]) {
                if (i-2 < 0 || nums[i] >= nums[i-2])
                    nums[i-1] = nums[i];
                else
                    nums[i] = nums[i-1];
                cnt += 1;
            }
        }
        return cnt <= 1;
    }
};

int main() {
    return 0;
}
