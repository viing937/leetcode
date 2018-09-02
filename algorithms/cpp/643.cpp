#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        int s = 0;
        for (int i = 0; i < k; i++)
            s += nums[i];
        double result = (double)s / k;
        for (int i = k; i < nums.size(); i++) {
            s -= nums[i-k];
            s += nums[i];
            result = max(result, (double)s / k);
        }
        return result;
    }
};

int main() {
    return 0;
}
