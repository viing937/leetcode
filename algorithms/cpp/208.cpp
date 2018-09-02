#include <iostream>
using namespace std;

class Trie {
private:
    struct TrieNode {
        TrieNode *next[26];
        int isWord;
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

    TrieNode *trie;
public:
    /** Initialize your data structure here. */
    Trie() {
        trie = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = trie, *pr;
        for (int i = 0; i < word.size(); i++) {
            pr = p;
            p = p->next[word[i]-'a'];
            if (!p) {
                p = new TrieNode();
                pr->next[word[i]-'a'] = p;
            }
        }
        p->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = trie;
        for (auto ch: word) {
            if (p == NULL)
                return false;
            p = p->next[ch-'a'];
        }
        return p && p->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = trie;
        for (auto ch: prefix) {
            if (p == NULL)
                return false;
            p = p->next[ch-'a'];
        }
        return p != NULL;
    }
};

int main() {
    return 0;
}
