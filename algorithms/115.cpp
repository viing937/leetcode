#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> dp(s.size(), 0);
        for (int i = 0; i < dp.size(); i++)
            if (s[i] == t[0])
                dp[i] = 1;
        for (int i = 1; i < t.size(); i++) {
            int acc = 0;
            for (int j = 0; j < s.size(); j++) {
                acc += dp[j];
                if (t[i] == s[j])
                    dp[j] = acc-dp[j];
                else
                    dp[j] = 0;
            }
        }
        int result = 0;
        for (int i = 0; i < dp.size(); i++)
            result += dp[i];
        return result;
    }
};

int main() {
    Solution solution;
    cout << solution.numDistinct("eee", "eee") << endl;
    return 0;
}
