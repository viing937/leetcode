#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() == 0)
            return 0;

        vector<int> cnt(26, 0);
        for (auto ch: s)
            cnt[ch-'a'] += 1;
        for (int i = 0; i < 26; i++)
            if (cnt[i] > 0 && cnt[i] < k)
                for (int j = 0; j < s.size(); j++)
                    if (s[j] == 'a'+i)
                        return max(longestSubstring(s.substr(0, j), k), longestSubstring(s.substr(j+1), k));

        return s.size();
    }
};

int main() {
    return 0;
}
