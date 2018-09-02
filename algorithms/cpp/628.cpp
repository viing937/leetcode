#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int> &nums) {
        int max1, max2, max3;
        int min1, min2;
        max1 = max2 = max3 = INT_MIN;
        min1 = min2 = INT_MAX;
        for (auto num: nums) {
            if (num > max3)
                max3 = num;
            if (max3 > max2)
                swap(max2, max3);
            if (max2 > max1)
                swap(max1, max2);

            if (num < min2)
                min2 = num;
            if (min2 < min1)
                swap(min1, min2);
        }
        return max1 * max(max2 * max3, min1 * min2);
    }
};

int main() {
    return 0;
}
