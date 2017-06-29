#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++)
            nums[i] = nums[i]==0 ? -1 : 1;
        int s = 0, result = 0;
        unordered_map<int, int> sumToIndex;
        sumToIndex[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            s += nums[i];
            if (sumToIndex.find(s) == sumToIndex.end())
                sumToIndex[s] = i;
            else
                result = max(result, i-sumToIndex[s]);
        }
        return result;
    }
};

int main() {
    return 0;
}
