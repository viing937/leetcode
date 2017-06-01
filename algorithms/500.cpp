#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<char>> letters = { {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
                                     {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
                                     {'z', 'x', 'c', 'v', 'b', 'n', 'm'} };
    int charFrom(char ch) {
        if (ch >= 'A' && ch <= 'Z')
            ch = ch-'A'+'a';
        for (int i = 0; i < 3; i++)
            if (find(letters[i].begin(), letters[i].end(), ch) != letters[i].end())
                return i;
        return -1;
    }

    int wordFrom(const string &s) {
        int first = charFrom(s[0]);
        for (int i = 1; i < s.size(); i++)
            if (first != charFrom(s[i]))
                return -1;
        return first;
    }

public:
    vector<string> findWords(vector<string> &words) {
        vector<string> result;
        for (auto word: words)
            if (wordFrom(word) >= 0)
                result.push_back(word);
        return result;
    }
};

int main() {
    return 0;
}
