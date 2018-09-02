#include <iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int mask = ~0;
        while (num & mask) mask <<= 1;
        return (~num) & (~mask);
    }
};

int main() {
    Solution solution;
    solution.findComplement(5);
    return 0;
}
