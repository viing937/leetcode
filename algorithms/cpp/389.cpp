#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnt(26, 0);
        for (auto ch: s)
            cnt[ch-'a'] += 1;
        for (auto ch: t)
            cnt[ch-'a'] -= 1;
        char result;
        for (int i = 0; i < 26; i++)
            if (cnt[i] < 0)
                result = 'a'+i;
        return result;
    }
};

int main() {
    return 0;
}
