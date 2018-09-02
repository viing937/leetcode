#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        if (nums.size() == 0 || nums[0].size() == 0)
            return nums;
        int m = nums.size(), n = nums[0].size();
        if (m*n != r*c)
            return nums;
        vector<vector<int>> result(r, vector<int>(c));
        for (int i = 0; i < m*n; i++)
            result[i/c][i%c] = nums[i/n][i%n];
        return result;
    }
};

int main() {
    return 0;
}
