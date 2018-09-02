#include <iostream>
#include <cmath>
using namespace std;

class Solution {
private:
    long createPalindrom(long firstHalf) {
        string palindrom = to_string(firstHalf);
        palindrom = palindrom + string(palindrom.rbegin(), palindrom.rend());
        return stol(palindrom);
    }
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        long upper = (long)pow(10, n) - 1, lower = upper / 10;
        long maxNumber = (long)upper * upper;
        long firstHalf = maxNumber / (long)pow(10, n);
        long palindrom = 0;
        while (true) {
            palindrom = createPalindrom(firstHalf);
            for (long i = upper; i > lower; i--) {
                if (palindrom / i > upper || i * i < palindrom)
                    break;
                if (palindrom % i == 0)
                    return palindrom % 1337;
            }
            firstHalf -= 1;
        }
    }
};

int main() {
    return 0;
}
