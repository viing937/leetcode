#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string str, string pattern) {
        int s = 0, p = 0, match = 0, starIdx = -1;
        while (s < str.size()) {
            if ((p < pattern.size() && pattern[p] == '?') || str[s] == pattern[p]) {
                s += 1;
                p += 1;
                continue;
            }
            if (p < pattern.size() && pattern[p] == '*') {
                match = s;
                starIdx = p;
                p += 1;
                continue;
            }
            if (starIdx != -1) {
                p = starIdx+1;
                s = match = match+1;
                continue;
            }
            return false;
        }
        while (p < pattern.size())
            if (pattern[p++] != '*')
                return false;
        return true;
    }
};

int main() {
    return 0;
}
