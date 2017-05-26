#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPatches(vector<int> &nums, int n) {
        int idx = 0, result = 0;
        long covered = 0;
        while (covered < n) {
            if (idx < nums.size() && nums[idx] <= covered+1)
                covered += nums[idx++];
            else {
                covered += covered+1;
                result += 1;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
