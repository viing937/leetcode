#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int, unordered_map<int, unordered_map<int, bool>>> cache;
    bool helper(string &s1, string &s2, string &s3, int i, int j, int k) {
        if (k < 0) return true;
        if (cache[i][j].find(k) != cache[i][j].end()) return cache[i][j][k];
        if (i >= 0 && s1[i] == s3[k]) {
            if (helper(s1, s2, s3, i-1, j, k-1)) {
                cache[i][j][k] = true;
                return true;
            }
        }
        if (j >= 0 && s2[j] == s3[k]) {
            if (helper(s1, s2, s3, i, j-1, k-1)) {
                cache[i][j][k] = true;
                return true;
            }
        }
        cache[i][j][k] = false;
        return false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        if (l1 + l2 != l3) return false;
        cache.clear();
        return helper(s1, s2, s3, l1-1, l2-1, l3-1);
    }
};

int main() {
    return 0;
}
