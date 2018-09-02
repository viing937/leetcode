#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string optimalDivision(vector<int> &nums) {
        string result;
        if (nums.size() <= 2) {
            for (int i = 0; i < nums.size(); i++)
                result += to_string(nums[i]) + "/";
            if (result.size() > 0)
                result.pop_back();
        } else {
            result = to_string(nums[0]) + "/(";
            for (int i = 1; i < nums.size()-1; i++)
                result += to_string(nums[i]) + "/";
            result += to_string(nums.back()) + ")";
        }
        return result;
    }
};

int main() {
    return 0;
}
