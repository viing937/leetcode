#include <iostream>
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        return n == 1 ? 1 : 2*(1+n/2-lastRemaining(n/2));
    }
};

int main() {
    return 0;
}
