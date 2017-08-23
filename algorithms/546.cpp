#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int helper(vector<int> &boxes, int i, int j, int k, int dp[][101][101]) {
        if (i > j) return 0;
        if (dp[i][j][k] > 0) return dp[i][j][k];
        while (i+1 <= j && boxes[i] == boxes[i+1])
            i += 1, k += 1;
        int result = (k+1)*(k+1) + helper(boxes, i+1, j, 0, dp);
        for (int m = i+1; m <= j; m++)
            if (boxes[m] == boxes[i])
                result = max(result, helper(boxes, i+1, m-1, 0, dp) + helper(boxes, m, j, k+1, dp));
        dp[i][j][k] = result;
        return result;
    }
public:
    int removeBoxes(vector<int> &boxes) {
        int n = boxes.size();
        int dp[101][101][101] = {0};
        return helper(boxes, 0, n-1, 0, dp);
    }
};

int main() {
    return 0;
}
