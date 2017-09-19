#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> maxLength(n, 1), count(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (nums[i] >= nums[j]) continue;
                if (maxLength[i]+1 > maxLength[j]) {
                    maxLength[j] = maxLength[i] + 1;
                    count[j] = count[i];
                }
                else if (maxLength[i]+1 == maxLength[j])
                    count[j] += count[i];
            }
        }
        int length = *max_element(maxLength.begin(), maxLength.end());
        int result = 0;
        for (int i = 0; i < n; i++)
            if (maxLength[i] == length)
                result += count[i];
        return result;
    }
};

int main() {
    return 0;
}
