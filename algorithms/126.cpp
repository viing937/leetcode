#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
private:
    bool helper(unordered_set<string> &words1, unordered_set<string> &words2,
                unordered_set<string> &dict, unordered_map<string, vector<string>> &nexts, bool backword) {
        if (words1.empty()) return false;
        if (words1.size() > words2.size()) return helper(words2, words1, dict, nexts, !backword);
        for (auto &word: words1)
            dict.erase(word);
        for (auto &word: words2)
            dict.erase(word);
        bool reach = false;
        unordered_set<string> words3;
        for (auto it = words1.begin(); it != words1.end(); ++it) {
            string word = *it;
            for (auto ch = word.begin(); ch < word.end(); ++ch) {
                char backup = *ch;
                for (*ch = 'a'; *ch <= 'z'; (*ch)++) {
                    if (*ch == backup) continue;
                    if (words2.find(word) != words2.end()) {
                        reach = true;
                        !backword ? nexts[*it].push_back(word): nexts[word].push_back(*it);
                    }
                    else if (!reach && dict.find(word) != dict.end()) {
                        words3.insert(word);
                        !backword ? nexts[*it].push_back(word): nexts[word].push_back(*it);
                    }
                }
                *ch = backup;
            }
        }
        return reach || helper(words2, words3, dict, nexts, !backword);
    }
    void getPath(string &beginWord, string &endWord, unordered_map<string, vector<string>> &nexts,
                 vector<string> &path, vector<vector<string>> &result) {
        if (beginWord == endWord)
            result.push_back(path);
        else {
            for (auto &word: nexts[beginWord]) {
                path.push_back(word);
                getPath(word, endWord, nexts, path, result);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        vector<vector<string>> result;
        vector<string> path(1, beginWord);
        if (beginWord == endWord) {
            result.push_back(path);
            return result;
        }
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return result;
        unordered_set<string> words1, words2;
        words1.insert(beginWord); words2.insert(endWord);
        unordered_map<string, vector<string>> nexts;
        if (helper(words1, words2, dict, nexts, false))
            getPath(beginWord, endWord, nexts, path, result);
        return result;
    }
};

int main() {
    string beginWord = "a", endWord = "c";
    vector<string> wordList = {"a","b","c"};
    Solution solution;
    solution.findLadders(beginWord, endWord, wordList);
    return 0;
}
