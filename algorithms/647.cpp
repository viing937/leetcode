#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        if (n <= 1) return n;
        int result = 0;
        for (int k = 0; k < n; k++) {
            int i = k, j = k;
            result += 1;
            while (i-1 >= 0 && j+1 < n && s[i-1] == s[j+1]) {
                i -= 1, j += 1;
                result += 1;
            }
        }
        for (int k = 0; k < n-1; k++) {
            if (s[k] != s[k+1]) continue;
            int i = k, j = k+1;
            result += 1;
            while (i-1 >= 0 && j+1 < n && s[i-1] == s[j+1]) {
                i -= 1, j += 1;
                result += 1;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
