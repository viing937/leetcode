#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> r(nums.begin(), nums.end());
        for (int i = 1; i < r.size(); i++) {
            int t = rand()%(i+1);
            swap(r[i], r[t]);
        }
        return r;
    }
};

int main() {
    return 0;
}
