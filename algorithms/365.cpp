#include <iostream>
using namespace std;

class Solution {
private:
    int gcd(int x, int y) {
        int t;
        while (y != 0) {
            t = y;
            y = x%y;
            x = t;
        }
        return x;
    }
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) return false;
        if (x == z || y == z || x+y == z) return true;
        return (z % gcd(x, y)) == 0;
    }
};

int main() {
    return 0;
}
