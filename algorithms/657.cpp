#include <iostream>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (auto ch: moves) {
            switch (ch) {
                case 'U': x += 1; break;
                case 'D': x -= 1; break;
                case 'R': y += 1; break;
                case 'L': y -= 1; break;
            }
        }
        return x == 0 && y == 0;
    }
};

int main() {
    return 0;
}
