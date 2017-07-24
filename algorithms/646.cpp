#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>> &pairs) {
        int n = pairs.size();
        if (n == 0) return 0;
        sort(pairs.begin(), pairs.end());
        int result = 1, end = pairs[0][1];
        for (int i = 1; i < n; i++) {
            if (pairs[i][0] > end) {
                result += 1;
                end = pairs[i][1];
            }
            else
                end = min(end, pairs[i][1]);
        }
        return result;
    }
};

int main() {
    return 0;
}
