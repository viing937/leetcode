#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> accu;
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        accu = vector<vector<int>>(m+1, vector<int>(n+1));
        fill(accu[0].begin(), accu[0].end(), 0);
        for (int i = 1; i <= m; i++) {
            accu[i][0] = 0;
            for (int j = 1; j <= n; j++)
                accu[i][j] = accu[i][j-1] + matrix[i-1][j-1];
            for (int j = 1; j <= n; j++)
                accu[i][j] += accu[i-1][j];
        }
        return;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return accu[row2+1][col2+1] - accu[row2+1][col1] - accu[row1][col2+1] + accu[row1][col1];
    }
};

int main() {
    return 0;
}
