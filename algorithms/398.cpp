#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    int pick(int target) {
        int result, cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                cnt += 1;
                if (rand() % cnt == 0)
                    result = i;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
