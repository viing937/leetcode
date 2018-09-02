#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        int result = 0, mask = 0;
        for (int i = 30; i >= 0; i--) {
            mask |= 1 << i;
            unordered_set<int> prefixs;
            for (auto num: nums)
                prefixs.insert(num & mask);
            int tmp = result | (1 << i);
            for (int prefix: prefixs) {
                if (prefixs.find(prefix ^ tmp) != prefixs.end()) {
                    result = tmp;
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
