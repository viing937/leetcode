#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> result;
    const string p = "()";
    void helper(const string &s, int si, int sj, int rev) {
        int stack = 0;
        for (int i = si; i < s.size(); i++) {
            if (s[i] == p[rev]) stack += 1;
            if (s[i] == p[1-rev]) stack -= 1;
            if (stack >= 0) continue;
            for (int j = sj; j <= i; j++)
                if (s[j] == p[1-rev] && (j == sj || s[j-1] != p[1-rev]))
                    helper(s.substr(0, j) + s.substr(j+1), i, j, rev);
            return;
        }
        string rs(s.rbegin(), s.rend());
        if (rev == 0)
            helper(rs, 0, 0, 1);
        else
            result.push_back(rs);
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        result.clear();
        helper(s, 0, 0, 0);
        return result;
    }
};

int main() {
    return 0;
}
