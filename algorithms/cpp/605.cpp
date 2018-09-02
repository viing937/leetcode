#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i])
                continue;
            if (i-1 >= 0 && flowerbed[i-1])
                continue;
            if (i+1 < flowerbed.size() && flowerbed[i+1])
                continue;
            n -= 1;
            i += 1;
        }
        return n <= 0;
    }
};

int main() {
    return 0;
}
