#include <iostream>
#include <cmath>
using namespace std;

class Solution {
private:
    bool isSquare(int n) {
        return pow((int)sqrt(n), 2) == n;
    }
public:
    bool judgeSquareSum(int c) {
        for (int a = 0; a <= sqrt(c); a++)
            if (isSquare(c-a*a))
                return true;
        return false;
    }
};

int main() {
    return 0;
}
