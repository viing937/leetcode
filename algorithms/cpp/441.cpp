#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        return (int) ((sqrt(1 + 8.0 * n) - 1) / 2);
    }
};

int main() {
    return 0;
}
