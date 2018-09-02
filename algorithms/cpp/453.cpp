#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minMoves(vector<int> &nums) {
        int sum = 0, minNum = INT_MAX;
        for (auto num: nums) {
            sum += num;
            minNum = min(minNum, num);
        }
        return sum - minNum * nums.size();
    }
};

int main() {
    return 0;
}
