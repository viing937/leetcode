#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    struct TrieNode {
        TrieNode *next[26];
        int idx;

        TrieNode() {
            idx = -1;
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
        }
        ~TrieNode() {
            for (int i = 0; i < 26; i++)
                if (next[i])
                    delete next[i];
        }
    };

    TrieNode *buildTrie(const vector<string> &words) {
        TrieNode *trie = new TrieNode();
        TrieNode *p, *pr;
        for (int i = 0; i < words.size(); i++) {
            const string &word = words[i];
            p = trie;
            for (int j = 0; j < word.size(); j++) {
                pr = p;
                p = p->next[word[j]-'a'];
                if (!p) {
                    p = new TrieNode();
                    pr->next[word[j]-'a'] = p;
                }
            }
            p->idx = i;
        }
        return trie;
    }

    TrieNode *trie;
    unordered_map<int, vector<string>> cache;

    vector<string> dfs(const string &s, int idx) {
        if (cache.find(idx) != cache.end())
            return cache[idx];

        vector<string> result;
        if (idx >= s.size()) {
            result.push_back("");
            return result;
        }

        TrieNode *p = trie;
        for (int i = idx; i < s.size(); i++) {
            p = p->next[s[i]-'a'];
            if (p == NULL)
                break;
            if (p->idx >= 0) {
                string word = s.substr(idx, i-idx+1);
                vector<string> splits = dfs(s, i+1);
                for (auto split: splits) {
                    result.push_back(word + (split.size()>0 ? " " : "") + split);
                }
            }
        }
        cache[idx] = result;
        return result;
    }
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        trie = buildTrie(wordDict);
        cache.clear();

        vector<string> splits;
        vector<string> result = dfs(s, 0);

        delete trie;
        return result;
    }
};

int main() {
    string s = "catsanddog";
    vector<string> wordDict = {"cat","cats","and","sand","dog"};
    Solution solution;
    solution.wordBreak(s, wordDict);
    return 0;
}
