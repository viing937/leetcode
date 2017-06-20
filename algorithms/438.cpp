#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size())
            return result;
        vector<int> hash(128, 0);
        for (auto ch: p)
            hash[ch] += 1;
        int left = 0, right = 0, count = p.size();
        while (right < s.size()) {
            if (hash[s[right++]]-- >= 1)
                count -= 1;
            if (count == 0)
                result.push_back(left);
            if (right-left == p.size() && hash[s[left++]]++ >= 0)
                count += 1;
        }
        return result;
    }
};

int main() {
    return 0;
}
