#include <iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int mask = num;
        for (int i = 30; i >= 0; i--) {
            if (!(mask & (1<<i))) continue;
            for (int j = 0; j <= i; j++)
                mask |= 1<<j;
            break;
        }
        return (~num)&mask;
    }
};

int main() {
    Solution solution;
    solution.findComplement(5);
    return 0;
}
