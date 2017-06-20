#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool isAnagram(const vector<int> &cnt, const vector<int> &tcnt) {
        for (int i = 0; i < 26; i++)
            if (cnt[i] != tcnt[i])
                return false;
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size())
            return result;
        vector<int> cnt(26, 0), tcnt(26, 0);
        for (auto ch: p)
            cnt[ch-'a'] += 1;
        for (int i = 0; i < s.size(); i++) {
            tcnt[s[i]-'a'] += 1;
            if (i >= p.size())
                tcnt[s[i-p.size()]-'a'] -= 1;
            if (i+1 >= p.size())
                if (isAnagram(cnt, tcnt))
                    result.push_back(i-p.size()+1);
        }
        return result;
    }
};

int main() {
    return 0;
}
