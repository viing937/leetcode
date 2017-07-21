#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> kmp(const string &str) {
        int n = str.size();
        vector<int> lps(n, 0);
        for (int i = 1, len = 0; i < n; ) {
            if (str[i] == str[len])
                lps[i++] = ++len;
            else if (len)
                len = lps[len-1];
            else
                lps[i++] = 0;
        }
        return lps;
    }
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        int n = haystack.size(), m = needle.size();
        vector<int> lps = kmp(needle);
        for (int i = 0, j = 0; i < n; ) {
            if (haystack[i] == needle[j])
                i += 1, j += 1;
            if (j == m) return i-j;
            if (i < n && haystack[i] != needle[j]) {
                if (j)
                    j = lps[j-1];
                else
                    i += 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    cout << solution.strStr("", "") << endl;
    return 0;
}
