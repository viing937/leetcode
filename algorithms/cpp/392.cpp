#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        int i = 0, j = 0;
        while (i < n) {
            if (j < m && t[i] == s[j])
                j += 1;
            i += 1;
        }
        return j == m;
    }
};

int main() {
    return 0;
}
