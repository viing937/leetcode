#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums) {
        stack<int> s;
        unordered_map<int, int> nextElement;
        for (int i = 0; i < nums.size(); i++) {
            while (!s.empty() && s.top() < nums[i]) {
                nextElement[s.top()] = nums[i];
                s.pop();
            }
            s.push(nums[i]);
        }
        vector<int> result;
        for (int i = 0; i < findNums.size(); i++) {
            if (nextElement.find(findNums[i]) != nextElement.end())
                result.push_back(nextElement[findNums[i]]);
            else
                result.push_back(-1);
        }
        return result;
    }
};

int main() {
    return 0;
}
