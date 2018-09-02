#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt1(26, 0), cnt2(26, 0);
        for (auto ch: ransomNote) cnt1[ch-'a'] += 1;
        for (auto ch: magazine) cnt2[ch-'a'] += 1;
        for (int i = 0; i < 26; i++)
            if (cnt1[i] > cnt2[i])
                return false;
        return true;
    }
};

int main() {
    return 0;
}
