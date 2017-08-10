#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> result;
    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
    struct TrieNode {
        TrieNode *next[26] = {0};
        const char *word = NULL;
        ~TrieNode() {
            for (int i = 0; i < 26; i++)
                delete next[i];
        }
    } *trie;
    void trieInsert(const string &word) {
        TrieNode *p = trie, *pr = trie;
        for (auto ch: word) {
            pr = p;
            if (pr->next[ch-'a'] == NULL)
                pr->next[ch-'a'] = p = new TrieNode;
            else
                p = p->next[ch-'a'];
        }
        p->word = word.data();
    }
    void helper(int row, int col, vector<vector<char>> &board, TrieNode *t) {
        if (t == NULL) return;
        if (t->word != NULL) {
            result.push_back(t->word);
            t->word = NULL;
        }
        int m = board.size(), n = board[0].size();
        char ch = board[row][col];
        board[row][col] = '#';
        for (int i = 0; i < 4; i++) {
            int x = row+dx[i], y = col+dy[i];
            if (x < 0 || x >= m) continue;
            if (y < 0 || y >= n) continue;
            if (board[x][y] == '#') continue;
            helper(x, y, board, t->next[board[x][y]-'a']);
        }
        board[row][col] = ch;
        return;
    }
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        int m = board.size(), n = board[0].size();
        result.clear();
        trie = new TrieNode;
        for (const auto &word: words)
            trieInsert(word);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                helper(i, j, board, trie->next[board[i][j]-'a']);
        delete trie;
        return result;
    }
};

int main() {
    return 0;
}
