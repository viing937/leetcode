#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(unsigned int a, unsigned int b) {
        unsigned int result = a ^ b, carry = a & b;
        while (carry) {
            a = result;
            b = carry << 1;
            result = a ^ b;
            carry = a & b;
        }
        return result;
    }
};

int main() {
    return 0;
}
