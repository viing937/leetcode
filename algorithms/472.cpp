#include <iostream>
#include <vector>
using namespace std;

// allocate global node pool to avoid MLE!
struct TrieNode;
TrieNode *pool[40000][26];
int poolIdx = 0;

struct TrieNode {
    TrieNode **next;
    bool isWord;

    TrieNode() {
        isWord = false;
        next = pool[poolIdx++];
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
    for (auto word: words) {
        p = trie;
        for (int j = 0; j < word.size(); j++) {
            pr = p;
            p = p->next[word[j]-'a'];
            if (!p) {
                p = new TrieNode();
                pr->next[word[j]-'a'] = p;
            }
        }
        p->isWord = true;
    }
    return trie;
}


class Solution {
private:
    bool helper(const TrieNode *trie, const char *s, bool isConcated) {
        const TrieNode *p = trie;
        int idx = -1;

        vector<int> q;
        while (s[++idx] != '\0') {
            p = p->next[s[idx]-'a'];
            if (p == NULL)
                break;
            if (p->isWord) {
                if (s[idx+1] == '\0') {
                    if (isConcated)
                        return true;
                }
                else
                    q.push_back(idx+1);
            }
        }

        while (q.size() > 0) {
            if (helper(trie, s+q.back(), true))
                return true;
            q.pop_back();
        }

        return false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        TrieNode *trie = buildTrie(words);
        vector<string> result;
        for (auto word: words) {
            if (helper(trie, word.c_str(), false))
                result.push_back(word);
        }
        delete trie;
        poolIdx = 0;
        return result;
    }
};

int main() {
    vector<string> words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    Solution solution;
    solution.findAllConcatenatedWordsInADict(words);
    return 0;
}
