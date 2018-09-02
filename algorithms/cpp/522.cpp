#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool isSubSeq(const string &s, const string &q) {
        if (s.size() < q.size())
            return false;
        int idx = 0;
        for (int i = 0; i < s.size() && idx < q.size(); i++) {
            if (s[i] == q[idx])
                idx += 1;
        }
        return idx == q.size();
    }
    static bool compare(const string &a, const string &b) {
        return a.size() > b.size();
    }
public:
    int findLUSlength(vector<string> &strs) {
        sort(strs.begin(), strs.end(), compare);
        for (int i = 0; i < strs.size(); i++) {
            int flag = false;
            for (int j = 0; j < strs.size(); j++)
                if (i != j && isSubSeq(strs[j], strs[i]))
                    flag = true;
            if (!flag)
                return strs[i].size();
        }
        return -1;
    }
};

int main() {
    vector<string> strs = {"aabbcc", "aabbcc","c","e","aabbcd"};
    Solution solution;
    solution.findLUSlength(strs);
    return 0;
}
