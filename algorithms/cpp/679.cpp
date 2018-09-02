#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool valid(vector<int> &nums) {
        double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        if (valid(a+b, c, d) || valid(a-b, c, d) || valid(a*b, c, d) || valid(a/b, c, d)) return true;
        if (valid(a, b+c, d) || valid(a, b-c, d) || valid(a, b*c, d) || valid(a, b/c, d)) return true;
        if (valid(a, b, c+d) || valid(a, b, c-d) || valid(a, b, c*d) || valid(a, b, c/d)) return true;
        return false;
    }
    bool valid(double a, double b, double c) {
        if (valid(a+b, c) || valid(a-b, c) || valid(a*b, c) || b&&valid(a/b, c)) return true;
        if (valid(a, b+c) || valid(a, b-c) || valid(a, b*c) || c&&valid(a, b/c)) return true;
        return false;
    }
    bool valid(double a, double b) {
        if (abs(a+b-24) < 1e-6 || abs(a-b-24) < 1e-6 || abs(a*b-24) < 1e-6 || b&&abs(a/b-24) < 1e-6)
            return true;
        return false;
    }
public:
    bool judgePoint24(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        do {
            if (valid(nums)) return true;
        } while (next_permutation(nums.begin(), nums.end()));
        return false;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 1};
    Solution solution;
    solution.judgePoint24(nums);
    return 0;
}
