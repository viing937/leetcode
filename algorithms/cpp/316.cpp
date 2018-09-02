#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void solve(string &s, int idx) {
        if (idx >= s.size())
            return;

        int cnt[26] = {0};
        for (int i = idx; i < s.size(); i++)
            cnt[s[i]-'a'] += 1;

        int pos = idx;
        for (int i = idx; i < s.size(); i++) {
            if (s[i] < s[pos])
                pos = i;
            if (--cnt[s[i]-'a'] == 0)
                break;
        }

        int t = idx;
        s[t++] = s[pos];
        for (int i = pos+1; i < s.size(); i++) {
            if (s[i] != s[idx])
                s[t++] = s[i];
        }
        s.resize(t);

        solve(s, idx+1);
    }
public:
    string removeDuplicateLetters(string s) {
        solve(s, 0);
        return s;
    }
};

int main() {
    Solution solution;
    solution.removeDuplicateLetters("ccacbaba");
    return 0;
}
