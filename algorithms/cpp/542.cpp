#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                result[i][j] = matrix[i][j]==0 ? 0 : INT_MAX/2;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i-1 >= 0)
                    result[i][j] = min(result[i][j], result[i-1][j]+1);
                if (j-1 >= 0)
                    result[i][j] = min(result[i][j], result[i][j-1]+1);
            }
        }
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (i+1 < m)
                    result[i][j] = min(result[i][j], result[i+1][j]+1);
                if (j+1 < n)
                    result[i][j] = min(result[i][j], result[i][j+1]+1);
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
