#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3)
            return false;

        int min = INT_MAX, minSecond = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= min)
                min = nums[i];
            else if (nums[i] <=  minSecond)
                minSecond = nums[i];
            else
                return true;
        }
        return false;
    }
};

int main() {
    return 0;
}
