#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> left(n, 0), right(n, n), height(n, 0);
        int result = 0;
        for (int i = 0; i < m; i++) {
            int curL = 0, curR = n;
            for (int j = 0; j < n; j++)
                height[j] = matrix[i][j]=='1' ? height[j]+1 : 0;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    left[j] = max(left[j], curL);
                else {
                    left[j] = 0;
                    curL = j+1;
                }
            }
            for (int j = n-1; j >= 0; j--) {
                if (matrix[i][j] == '1')
                    right[j] = min(right[j], curR);
                else {
                    right[j] = n;
                    curR = j;
                }
            }
            for (int j = 0; j < n; j++)
                result = max(result, (right[j]-left[j])*height[j]);
        }
        return result;
    }
};

int main() {
    return 0;
}
