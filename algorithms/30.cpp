#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> result;
        if (s.size() == 0 || words.size() == 0)
            return result;
        unordered_map<string, int> dict;
        for (auto word: words)
            dict[word] += 1;
        int wordLen = words[0].size();
        for (int i = 0; i < wordLen; i++) {
            int left = i, cnt = 0;
            unordered_map<string, int> tdict;
            for (int j = i; j+wordLen <= s.size(); j += wordLen) {
                string word = s.substr(j, wordLen);
                if (dict[word] == 0) {
                    left = j + wordLen;
                    cnt = 0;
                    tdict.clear();
                }
                else {
                    tdict[word] += 1;
                    if (tdict[word] <= dict[word])
                        cnt += 1;
                    else {
                        while (tdict[word] > dict[word]) {
                            string newWord = s.substr(left, wordLen);
                            tdict[newWord] -= 1;
                            if (tdict[newWord] < dict[newWord])
                                cnt -= 1;
                            left += wordLen;
                        }
                    }
                    if (cnt == words.size()) {
                        result.push_back(left);
                        tdict[s.substr(left, wordLen)] -= 1;
                        cnt -= 1;
                        left += wordLen;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
