#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
private:
    struct TrieNode {
        bool isWord;
        TrieNode *next[26];
        TrieNode() {
            isWord = false;
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
        }
        ~TrieNode() {
            for (int i = 0; i < 26; i++)
                delete next[i];
        }
    } *trie = NULL;
    void insert(const string &word) {
        TrieNode *p = trie, *pr = p;
        for (auto ch: word) {
            pr = p;
            p = p->next[ch-'a'];
            if (p == NULL) {
                p = new TrieNode();
                pr->next[ch-'a'] = p;
            }
        }
        p->isWord = true;
    }
    string searchRoot(const string &word) {
        int n = word.size();
        TrieNode *p = trie;
        for (int i = 0; i < n; i++) {
            p = p->next[word[i]-'a'];
            if (p == NULL) return word;
            if (p->isWord) return word.substr(0, i+1);
        }
        return word;
    }
public:
    string replaceWords(vector<string> &dict, string sentence) {
        trie = new TrieNode();
        for (const string &word: dict)
            insert(word);
        stringstream ssin(sentence), ssout;
        string word;
        ssin >> word;
        ssout << searchRoot(word);
        while (ssin >> word)
            ssout << " " << searchRoot(word);
        delete trie;
        return ssout.str();
    }
};

int main() {
    return 0;
}
