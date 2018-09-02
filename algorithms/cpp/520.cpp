#include <iostream>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int upcase = 0, downcase = 0;
        for (auto ch: word) {
            if (ch >= 'A' && ch <= 'Z')
                upcase += 1;
            if (ch >= 'a' && ch <= 'z')
                downcase += 1;
        }
        if (upcase == word.size())
            return true;
        if (downcase == word.size())
            return true;
        if (upcase == 1 && word[0] >= 'A' && word[0] <= 'Z')
            return true;
        return false;
    }
};

int main() {
    return 0;
}
