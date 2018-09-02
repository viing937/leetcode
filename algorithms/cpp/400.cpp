#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
private:
    vector<long> nth = {0, 9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889, 8888888889};
public:
    int findNthDigit(int n) {
        int start = 1, len = 1;
        while (n > nth[len]) {
            len += 1;
            start *= 10;
        }
        int num = start + (n-nth[len-1]-1)/len;
        int pos = (n-nth[len-1]-1)%len;
        return num / (int)pow(10, len-pos-1) % 10;
    }
};

int main() {
    Solution solution;
    cout << solution.findNthDigit(1000000000) << endl;
    return 0;
}
