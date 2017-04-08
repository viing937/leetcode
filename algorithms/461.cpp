#include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int t = x ^ y;
        int result = 0;
        while (t) {
            result += t & 1;
            t = t >> 1;
        }
        return result;
    }
};

int main() {
    return 0;
}
