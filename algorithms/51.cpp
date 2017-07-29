#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> pos;
    vector<bool> flagRow, flag45, flag135;
    vector<vector<string>> result;
    void helper(int col, int n) {
        if (col == n) {
            result.emplace_back(n, string(n, '.'));
            for (int i = 0; i < n; i++)
                result.back()[pos[i]][i] = 'Q';
            return;
        }
        for (int row = 0; row < n; row++) {
            if (!flagRow[row] && !flag45[row+col] && !flag135[row-col+n-1]) {
                pos[col] = row;
                flagRow[row] = flag45[row+col] = flag135[row-col+n-1] = true;
                helper(col+1, n);
                flagRow[row] = flag45[row+col] = flag135[row-col+n-1] = false;
            }
        }
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        pos = vector<int>(n);
        flagRow = vector<bool>(n, false);
        flag45 = vector<bool>(2*n-1, false);
        flag135 = vector<bool>(2*n-1, false);
        helper(0, n);
        return result;
    }
};

int main() {
    return 0;
}
