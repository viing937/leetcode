#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        int result = 1;
        for (int i = 0, j = 1; j < nums.size(); j++) {
            if (nums[j] <= nums[j-1])
                i = j;
            result = max(result, j-i+1);
        }
        return result;
    }
};

int main() {
    return 0;
}
