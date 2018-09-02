#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> result;
        for (auto num: nums) {
            num = abs(num);
            if (nums[num-1] < 0) {
                result.push_back(num);
            } else {
                nums[num-1] *= -1;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
