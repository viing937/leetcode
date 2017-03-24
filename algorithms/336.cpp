#include <iostream>
#include <vector>
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
            for (int j = word.size()-1; j >= 0; j--) {
                if (!p) {
                    p = new TrieNode();
                    pr->next[word[j+1]-'a'] = p;
                }
                pr = p;
                p = p->next[word[j]-'a'];
            }
            if (!p) {
                p = new TrieNode();
                pr->next[word[0]-'a'] = p;
            }
            p->idx = i;
        }
        return trie;
    }

    bool isPal(const string &word) {
        int i = 0, j = word.size()-1;
        while (i < j) {
            if (word[i] != word[j])
                return false;
            i += 1, j -= 1;
        }
        return true;
    }

    void helper(string &suffix, vector< vector<int> > &result, TrieNode *p, int wordIdx) {
        if (p->idx >= 0) {
            if (suffix != "" && isPal(suffix)) {
                result.push_back({wordIdx, p->idx});
            }
        }
        for (int i = 0; i < 26; i++) {
            if (p->next[i]) {
                suffix.push_back('a'+i);
                helper(suffix, result, p->next[i], wordIdx);
                suffix.pop_back();
            }
        }
    }
public:
    vector< vector<int> > palindromePairs(vector<string> &words) {
        vector< vector<int> > result;
        TrieNode *trie = buildTrie(words);

        if (trie->idx >= 0) {
            for (int i = 0; i < words.size(); i++) {
                if (isPal(words[i]) && i != trie->idx) {
                    result.push_back({i, trie->idx});
                    result.push_back({trie->idx, i});
                }
            }
        }

        for (int i = 0; i < words.size(); i++) {
            TrieNode *p = trie;
            string &word = words[i];

            if (word == "")
                continue;

            bool flag = false;
            for (int j = 0; j < word.size(); j++) {
                char ch = word[j];
                if (!p->next[ch-'a'])
                {
                    flag = true;
                    break;
                }
                p = p->next[ch-'a'];
                if (p->idx >= 0) {
                    if (i != p->idx && isPal(word+words[p->idx]))
                        result.push_back({i, p->idx});
                }
            }
            if (!flag) {
                string suffix = "";
                helper(suffix, result, p, i);
            }
        }

        delete trie;
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> words = {"abcd","dcba","lls","s","sssll"};
    solution.palindromePairs(words);
    return 0;
}
