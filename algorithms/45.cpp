#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int result = 0;
        int reach = 0, nextReach = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            nextReach = max(nextReach, i + nums[i]);
            if (i == reach) {
                result += 1;
                reach = nextReach;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
