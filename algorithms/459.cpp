#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> kmp(const string &s) {
        int n = s.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n; ) {
            if (s[i] == s[len])
                lps[i++] = ++len;
            else if (len)
                len = lps[len-1];
            else
                lps[i++] = 0;
        }
        return lps;
    }
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> lps = kmp(s);
        int len = lps[n-1];
        return len > 0 && (n % (n-len) == 0);
    }
};

int main() {
    return 0;
}
