#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string> &d) {
        vector<int> matchIdx(d.size(), 0);
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < d.size(); j++) {
                if (matchIdx[j] >= d[j].size()) continue;
                if (s[i] == d[j][matchIdx[j]]) matchIdx[j]++;
            }
        }
        string result = "";
        for (int i = 0; i < d.size(); i++) {
            if (matchIdx[i] < d[i].size()) continue;
            if (d[i].size() > result.size())
                result = d[i];
            if (d[i].size() == result.size() && d[i] < result)
                result = d[i];
        }
        return result;
    }
};

int main() {
    return 0;
}
