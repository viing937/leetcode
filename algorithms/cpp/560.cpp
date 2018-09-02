#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int res = 0, s = 0;
        unordered_map<int, int> preSum;
        preSum[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            res += preSum[s-k];
            preSum[s] += 1;
        }
        return res;
    }
};

int main() {
    return 0;
}
