#include <iostream>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        long t = n;
        int result = 0;
        while (t != 1) {
            result += 1;
            if (t % 2) {
                long a = t-1, b = t+1;
                while (a%2 == 0)
                    a /= 2;
                while (b%2 == 0)
                    b /= 2;
                if (a <= b)
                    t -= 1;
                else
                    t += 1;
            }
            else
                t /= 2;
        }
        return result;
    }
};

int main() {
    return 0;
}
