#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left < right) {
            int mid = left + (right-left)/2;
            int cnt = 0;
            for (int i = 0; i < m; i++)
                cnt += min(mid / (i+1), n);
            if (cnt < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

int main() {
    Solution solution;
    solution.findKthNumber(2, 3, 6);
    return 0;
}
