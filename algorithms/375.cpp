#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int, unordered_map<int, int>> m;
    int helper(int left, int right) {
        if (left >= right) return 0;
        if (m[left].find(right) != m[left].end()) return m[left][right];
        int result = INT32_MAX;
        for (int i = left; i <= right; i++)
            result = min(result, i + max(helper(left, i-1), helper(i+1, right)));
        m[left][right] = result;
        return result;
    }
public:
    int getMoneyAmount(int n) {
        m.clear();
        return helper(1, n);
    }
};

int main() {
    return 0;
}
