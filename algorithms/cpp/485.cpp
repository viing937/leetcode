#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int result = 0, cnt = 0;
        for (auto num: nums) {
            if (num == 1) {
                cnt += 1;
                result = max(result, cnt);
            }
            else
                cnt = 0;
        }
        return result;
    }
};

int main() {
    return 0;
}
