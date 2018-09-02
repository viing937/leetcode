#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.size() == 0)
            return 0;
        int a = 1, b = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1])
                a = b+1;
            if (nums[i] < nums[i-1])
                b = a+1;
        }
        return max(a, b);
    }
};

int main() {
    return 0;
}
