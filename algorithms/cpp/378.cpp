#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n-1][n-1];
        while (left < right) {
            int middle = left + (right-left)/2;
            int cnt = 0;
            for (int i = 0; i < n; i++)
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), middle) - matrix[i].begin();
            if (cnt < k)
                left = middle +1;
            else
                right = middle;
        }
        return left;
    }
};

int main() {
    return 0;
}
