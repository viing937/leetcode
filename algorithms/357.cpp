#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> result = {1, 10, 91, 739, 5275, 32491, 168571, 712891, 2345851, 5611771, 8877691};
public:
    int countNumbersWithUniqueDigits(int n) {
        n = n>10 ? 10 : n;
        return result[n];
    }
};

int main() {
    return 0;
}
