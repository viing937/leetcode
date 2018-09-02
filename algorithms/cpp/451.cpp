#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
    static bool compare(const pair<char, int> &a, const pair<char, int> &b) {
        return a.second > b.second;
    }
public:
    string frequencySort(string s) {
        map<char, int> cnt;
        for (auto ch: s)
            cnt[ch] += 1;
        vector<pair<char, int>> toSort;
        for (auto it = cnt.begin(); it != cnt.end(); ++it)
            toSort.push_back(*it);
        sort(toSort.begin(), toSort.end(), compare);
        string result;
        for (auto it = toSort.begin(); it != toSort.end(); ++it) {
            for (int i = 0; i < it->second; i++)
                result += it->first;
        }
        return result;
    }
};

int main() {
    return 0;
}
