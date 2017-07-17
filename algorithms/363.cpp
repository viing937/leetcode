#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        int row = matrix.size(), col = matrix[0].size();
        int result = INT_MIN;
        for (int l = 0; l < col; l++) {
            vector<int> sum(row, 0);
            for (int r = l; r < col; r++) {
                for (int i = 0; i < row; i++)
                    sum[i] += matrix[i][r];
                set<int> accSet;
                accSet.insert(0);
                int acc = 0;
                for (int i = 0; i < row; i++) {
                    acc += sum[i];
                    auto it = accSet.lower_bound(acc-k);
                    if (it != accSet.end())
                        result = max(result, acc - *it);
                    accSet.insert(acc);
                }
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 0, 1}, {0, -2, 3}};
    Solution solution;
    solution.maxSumSubmatrix(matrix, 2);
    return 0;
}
