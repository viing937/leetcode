#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int binarySearch(vector<string> &wordDict, const string &word) {
        int l = 0, r = wordDict.size()-1;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (wordDict[m] == word)
                return m;
            else if (wordDict[m] < word)
                l = m+1;
            else
                r = m-1;
        }
        return -1;
    }
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int n = s.size();

        sort(wordDict.begin(), wordDict.end());

        vector<bool> dp(n+1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (dp[j] && binarySearch(wordDict, s.substr(j, i-j)) >= 0) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

int main() {
    vector<string> wordDict = {"a", "b"};
    string s = "ab";

    Solution solution;
    solution.wordBreak(s, wordDict);
    return 0;
}
