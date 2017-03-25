#include <iostream>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int cnt[26] = {0};
        for (auto ch : s) {
            cnt[ch-'a'] += 1;
        }
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (cnt[ch-'a'] == 1)
                return i;
        }
        return -1;
    }
};

int main() {
    return 0;
}
