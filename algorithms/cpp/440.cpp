#include <iostream>
using namespace std;

class Solution {
private:
    int calSteps(long n, long n1, long n2) {
        int steps = 0;
        while (n1 <= n) {
            steps += min(n+1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
public:
    int findKthNumber(int n, int k) {
        k -= 1;
        int ret = 1;
        while (k > 0) {
            int steps = calSteps(n, ret, ret+1);
            if (steps <= k) {
                k -= steps;
                ret += 1;
            }
            else {
                k -= 1;
                ret *= 10;
            }
        }
        return ret;
    }
};

int main() {
    return 0;
}
