#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix) {
        vector<int> result;
        if (matrix.size() == 0)
            return result;
        int row = matrix.size(), col = matrix[0].size();
        result.reserve(row*col);
        for (int i = 0; i < row+col; i++) {
            if (i%2) {
                for (int j = max(0, i-col+1); j <= i && j < row; j++)
                    result.push_back(matrix[j][i-j]);
            }
            else {
                for (int j = max(0, i-row+1); j <= i && j < col; j++)
                    result.push_back(matrix[i-j][j]);
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
