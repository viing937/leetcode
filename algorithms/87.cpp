#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        int length = s1.size();
        vector<int> count(26, 0);
        for (int i = 0; i < length; i++) {
            count[s1[i]-'a'] += 1;
            count[s2[i]-'a'] -= 1;
        }
        for (int i = 0; i < count.size(); i++)
            if (count[i] != 0)
                return false;
        for (int i = 1; i < length; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if (isScramble(s1.substr(0, i), s2.substr(length-i)) && isScramble(s1.substr(i), s2.substr(0, length-i)))
                return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    solution.isScramble("oatzzffqpnwcxhejzjsnpmkmzngneo", "acegneonzmkmpnsjzjhxwnpqffzzto");
    return 0;
}
