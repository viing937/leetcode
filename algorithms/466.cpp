#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int k = 0;
        int count = 0;
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < s1.size(); ) {
                if (s1[j] == s2[k]) {
                    j += 1;
                    k += 1;
                    if (k == s2.size()) {
                        k = 0;
                        count += 1;
                    }
                }
                else
                    j += 1;
                if (j == s1.size() && k == 0)
                    return (int)(n1 * 1.0 / (i+1) * count / n2);
            }
        }
        return count / n2;
    }
};

int main() {
    Solution solution;
    cout << solution.getMaxRepetitions("aaa", 3, "aa", 1) << endl;
    return 0;
}
