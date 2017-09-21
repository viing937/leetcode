#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string> &bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        if (!dict.count(end)) return -1;
        int n = start.size(), step = 0;
        unordered_set<string> bset, eset, *set1, *set2;
        bset.insert(start);
        eset.insert(end);
        while (!bset.empty() && !end.empty()) {
            step += 1;
            if (bset.size() <= eset.size())
                set1 = &bset, set2 = &eset;
            else
                set1 = &eset, set2 = &bset;
            unordered_set<string> tmp;
            for (auto it = set1->begin(); it != set1->end(); ++it) {
                for (int i = 0; i < n; i++) {
                    string dna = *it;
                    for (auto ch: "ACGT") {
                        dna[i] = ch;
                        if (set2->count(dna)) return step;
                        if (!dict.count(dna)) continue;
                        tmp.insert(dna);
                        dict.erase(dna);
                    }
                }
            }
            *set1 = tmp;
        }
        return -1;
    }
};

int main() {
    vector<string> bank = {"AACCGGTA"};
    Solution solution;
    solution.minMutation("AACCGGTT", "AACCGGTA", bank);
    return 0;
}
