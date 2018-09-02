#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> cnt;
        for (auto ch : s)
            cnt[ch] += 1;

        int result = 0, single = 0;
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            single += it->second % 2;
            result += it->second / 2 * 2;
        }
        return result + (single > 0 ? 1 : 0);
    }
};

int main() {
    return 0;
}
