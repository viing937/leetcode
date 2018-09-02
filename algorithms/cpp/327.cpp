#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int mergeSort(int left, int right, vector<long> &preSum, int lower, int upper) {
        if (left+1 >= right) return 0;
        int middle = left + (right-left)/2;
        int count = mergeSort(left, middle, preSum, lower, upper)
                  + mergeSort(middle, right, preSum, lower, upper);
        int j = middle, k = middle, t = middle;
        vector<long> temp(right-left);
        for (int i = left, r = 0; i < middle; i++) {
            while (k < right && preSum[k] - preSum[i] < lower) k += 1;
            while (j < right && preSum[j] - preSum[i] <= upper) j += 1;
            count += j - k;
            while (t < right && preSum[t] < preSum[i]) temp[r++] = preSum[t++];
            temp[r++] = preSum[i];
        }
        copy(temp.begin(), temp.begin()+t-left, preSum.begin()+left);
        return count;
    }
public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        vector<long> preSum(nums.size()+1, 0);
        for (int i = 1; i <= nums.size(); i++)
            preSum[i] = preSum[i-1] + nums[i-1];
        return mergeSort(0, preSum.size(), preSum, lower, upper);
    }
};

int main() {
    vector<int> nums = {-2, 5, -1};
    Solution solution;
    cout << solution.countRangeSum(nums, -2, 2) << endl;
    return 0;
}
