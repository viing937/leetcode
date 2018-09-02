#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    const int MOD = 1337;
    int powmod(int a, int k) {
        a %= MOD;
        int result = 1;
        for (int i = 0; i < k; i++)
            result = result * a % MOD;
        return result;
    }
public:
    int superPow(int a, vector<int> &b) {
        if (b.empty()) return 1;
        int lastDigit = b.back();
        b.pop_back();
        return powmod(superPow(a, b), 10) * powmod(a, lastDigit) % MOD;
    }
};

int main() {
    return 0;
}
