#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    string smallestGoodBase(string n) {
        unsigned long long num = stoll(n);
        int maxLen = log2(num)+1;
        for (int k = maxLen; k >= 3; k--) {
            unsigned long long b = pow(num, 1.0/(k-1)), cur = 1, sum = 1;
            for (int i = 1; i < k; i++) {
                cur *= b;
                sum += cur;
            }
            if (sum == num)
                return to_string(b);
        }
        return to_string(num-1);
    }
};

int main() {
    return 0;
}
