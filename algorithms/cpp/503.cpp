#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        vector<int> res(nums.size(), -1);
        stack<int> s;
        for (int i = nums.size()-1; i >= 0; i--)
            s.push(nums[i]);
        for (int i = nums.size()-1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums[i])
                s.pop();
            if (!s.empty())
                res[i] = s.top();
            s.push(nums[i]);
        }
        return res;
    }
};

int main() {
    return 0;
}
