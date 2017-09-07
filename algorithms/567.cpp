#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        if (len1 > len2) return false;
        vector<int> a(26, 0), b(26, 0);
        for (auto ch: s1) a[ch-'a'] += 1;
        for (int i = 0; i < len2; i++) {
            b[s2[i]-'a'] += 1;
            if (i-len1 >= 0)
                b[s2[i-len1]-'a'] -= 1;
            if (a == b)
                return true;
        }
        return false;
    }
};

int main() {
    return 0;
}
