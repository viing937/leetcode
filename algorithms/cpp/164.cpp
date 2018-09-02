#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &nums) {
        if (nums.size() < 2)
            return 0;

        int maxNum = nums[0];
        for (int i = 0; i < nums.size(); i++)
            maxNum = max(maxNum, nums[i]);

        int exp = 1;
        vector<int> aux(nums.size());

        while (maxNum / exp) {
            vector<int> count(10);

            for (int i = 0; i < nums.size(); i++)
                count[nums[i]/exp%10] += 1;

            for (int i = 1; i < 10; i++)
                count[i] += count[i-1];

            for (int i = nums.size()-1; i >= 0; i--)
                aux[--count[nums[i]/exp%10]] = nums[i];

            for (int i = 0; i < nums.size(); i++)
                nums[i] = aux[i];

            exp *= 10;
        }

        int result = nums[1] - nums[0];
        for (int i = 2; i < nums.size(); i++)
            result = max(result, nums[i]-nums[i-1]);

        return result;
    }
};

int main() {
    return 0;
}
