#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<int> helper(vector<int> &heights, bool isReversed) {
        if (isReversed) reverse(heights.begin(), heights.end());
        vector<int> result(heights.size(), 0);
        stack<int> s;
        for (int i = 0; i < heights.size(); i++) {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            if (s.empty())
                result[i] = max(result[i], heights[i] * (i+1));
            else
                result[i] = max(result[i], heights[i] * (i-s.top()));
            s.push(i);
        }
        if (isReversed) {
            reverse(heights.begin(), heights.end());
            reverse(result.begin(), result.end());
        }
        return result;
    }
public:
    int largestRectangleArea(vector<int> &heights) {
        vector<int> left = helper(heights, false);
        vector<int> right = helper(heights, true);
        int result = 0;
        for (int i = 0; i < heights.size(); i++)
            result = max(result, left[i]+right[i]-heights[i]);
        return result;
    }
};

int main() {
    return 0;
}
