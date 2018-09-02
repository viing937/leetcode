#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num < 2)
            return false;
        int sum = 1;
        for (int i = 2; i < sqrt(num); i++)
            if (num%i == 0)
                sum += i + num/i;
        return sum == num;
    }
};

int main() {
    return 0;
}
