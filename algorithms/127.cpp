#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        set<string> words(wordList.begin(), wordList.end());
        queue<pair<int, string>> q;
        q.push(make_pair(1, beginWord));

        while (!q.empty()) {
            int step = q.front().first;
            string word = q.front().second;
            q.pop();

            if (word == endWord)
                return step;

            for (auto it = words.begin(); it != words.end();) {
                int cnt = 0;
                for (int i = 0; i < word.size(); i++)
                    cnt += word[i] != (*it)[i] ? 1 : 0;
                if (cnt == 1) {
                    q.push(make_pair(step+1, *it));
                    it = words.erase(it);
                } else
                    it++;
            }
        }
        return 0;
    }
};

int main() {
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    Solution solution;
    solution.ladderLength("hit", "cog", wordList);
    return 0;
}
