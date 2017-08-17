#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int strongPasswordChecker(string s) {
        int n = s.size();
        int needUpper = 1, needLower = 1, needDigit = 1;
        vector<int> repeat(n, 0);
        for (int i = 0; i < n; ) {
            if (isupper(s[i])) needUpper = 0;
            if (islower(s[i])) needLower = 0;
            if (isdigit(s[i])) needDigit = 0;
            int j = i;
            while (i < n && s[i] == s[j]) i++;
            repeat[j] = i-j;
        }
        int totalNeed = needUpper + needLower + needDigit;
        if (n < 6) return totalNeed + max(0, 6-n-totalNeed);
        int needDelete = max(0, n - 20), leftOver = 0;
        int result = needDelete;
        for (int k = 1; k <= 2; k++) {
            for (int i = 0; i < n && needDelete > 0; i++) {
                if (repeat[i] < 3 || repeat[i] % 3 != (k-1)) continue;
                int numDelete = min(needDelete, k);
                repeat[i] -= numDelete;
                needDelete -= numDelete;
            }
        }
        for (int i = 0; i < n; i++) {
            if (repeat[i] >= 3 && needDelete > 0) {
                int numDelete = min(needDelete, repeat[i]-2);
                repeat[i] -= numDelete;
                needDelete -= numDelete;
            }
            leftOver += repeat[i] / 3;
        }
        result += max(totalNeed, leftOver);
        return result;
    }
};

int main() {
    return 0;
}
