#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        int n = nums.size();

        vector<int> result;
        for (int i = 0; i < n; i++)
            nums[(nums[i]-1)%n] += n;
        for (int i = 0; i < n; i++)
            if (nums[i] <= n)
                result.push_back(i+1);

        return result;
    }
};

int main() {
    return 0;
}
