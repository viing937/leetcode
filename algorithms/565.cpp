#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int helper(int cur, int depth, const vector<int> &nums, vector<bool> &visited) {
        int n = nums.size();
        int successor = nums[cur];
        if (successor < n && !visited[successor]) {
            visited[successor] = true;
            return helper(successor, depth+1, nums, visited);
        }
        else
            return depth+1;
    }
public:
    int arrayNesting(vector<int> &nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                result = max(result, helper(i, 0, nums, visited));
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
