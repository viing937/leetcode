#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class MagicDictionary {
private:
    unordered_map<string, unordered_map<int, unordered_set<char>>> mDict;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (const auto &word: dict) {
            int n = word.size();
            for (int i = 0; i < n; i++)
                mDict[word.substr(0, i) + word.substr(i+1)][i].insert(word[i]);
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int n = word.size();
        for (int i = 0; i < n; i++) {
            string key = word.substr(0, i) + word.substr(i+1);
            if (mDict[key][i].size() > 1)
                return true;
            if (mDict[key][i].size() == 1 && mDict[key][i].find(word[i]) == mDict[key][i].end())
                return true;
        }
        return false;
    }
};

int main() {
    return 0;
}
