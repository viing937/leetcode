#include <iostream>
using namespace std;

class WordDictionary {
private:
    struct TrieNode {
        TrieNode *next[26];
        bool isWord;

        TrieNode() {
            isWord = false;
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
        }
        ~TrieNode() {
            for (int i = 0; i < 26; i++)
                if (next[i])
                    delete next[i];
        }
    };

    TrieNode *trie = NULL;

    bool searchHelper(const string &word, int idx, TrieNode *p) {
        if (idx == word.size())
            return p != NULL && p->isWord;
        if (p == NULL)
            return false;
        if (word[idx] == '.') {
            for (int i = 0; i < 26; i++)
                if (searchHelper(word, idx+1, p->next[i]))
                    return true;
        }
        else {
            if (searchHelper(word, idx+1, p->next[word[idx]-'a']))
                return true;
        }
        return false;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        trie = new TrieNode;
    }
    ~WordDictionary() {
        delete trie;
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *p = trie, *pr = NULL;
        for (auto ch: word) {
            pr = p;
            p = p->next[ch-'a'];
            if (p == NULL) {
                p = new TrieNode;
                pr->next[ch-'a'] = p;
            }
        }
        p->isWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchHelper(word, 0, trie);
    }
};

int main() {
    return 0;
}
