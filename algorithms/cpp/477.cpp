#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int> &nums) {
        vector<int> cnt(32, 0);
        for (auto num: nums) {
            int idx = 0;
            while (num) {
                cnt[idx++] += num&1;
                num = num>>1;
            }
        }
        int result = 0;
        for (int i = 0; i < cnt.size(); i++)
            result += cnt[i] * (nums.size()-cnt[i]);
        return result;
    }
};

int main() {
    return 0;
}
