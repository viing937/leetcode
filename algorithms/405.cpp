#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    const string HEX = "0123456789abcdef";
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string result;
        unsigned int k = num;
        while (k) {
            result.push_back(HEX[k & 0xf]);
            k = k >> 4;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    return 0;
}
