#include <iostream>
using namespace std;

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l <= r) {
            int m = l+(r-l)/2;
            int g = guess(m);
            if (g < 0)
                r = m-1;
            else if (g > 0)
                l = m+1;
            else
                return m;
        }
        return -1;
    }
};

int main() {
    return 0;
}
