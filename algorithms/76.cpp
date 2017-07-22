#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        int sLen = s.size(), tLen = t.size();
        int require = tLen;
        vector<int> count(128, 0);
        vector<bool> chSet(128, false);
        for (int i = 0; i < tLen; i++) {
            count[t[i]] += 1;
            chSet[t[i]] = true;
        }
        int i = -1, j = 0;
        int minLen = INT_MAX, minStart = 0;
        while (i < sLen && j < sLen) {
            if (require) {
                char ch = s[++i];
                count[ch] -= 1;
                if (chSet[ch] && count[ch] >= 0)
                    require -= 1;
            }
            else {
                if (i-j+1 < minLen) {
                    minLen = i-j+1;
                    minStart = j;
                }
                char ch = s[j++];
                count[ch] += 1;
                if (chSet[ch] && count[ch] > 0)
                    require += 1;
            }
        }
        return minLen < INT_MAX ? s.substr(minStart, minLen) : "";
    }
};

int main() {
    return 0;
}
