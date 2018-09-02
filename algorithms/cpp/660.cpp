#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int newInteger(int n) {
        vector<long> preCount = {1, 9, 81, 729, 6561, 59049, 531441, 4782969,
                                 43046721, 387420489, 1865828329, 22876792454961,
                                 205891132094649, 1853020188851841, 851717672992089};
        int length = 1;
        while (n >= preCount[length]) length++;
        int result = 0;
        while (length > 0) {
            result = result * 10 + n / preCount[--length];
            n %= preCount[length];
        }
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.newInteger(800000000) << endl;
    return 0;
}
