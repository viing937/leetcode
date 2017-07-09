#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> sumToIndex;
        sumToIndex[0] = -1;
        int s = 0;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            if (k != 0)
                s %= k;
            if (sumToIndex.find(s) != sumToIndex.end()) {
                if (i - sumToIndex[s] > 1)
                    return true;
            }
            else
                sumToIndex[s] = i;
        }
        return false;
    }
};

int main() {
    return 0;
}
