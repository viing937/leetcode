#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(p.size(), 1);
        vector<int> cnt(26, 0);
        for (int i = 1; i < p.size(); i++) {
            if (p[i]-'a' == (p[i-1]-'a'+1)%26)
                dp[i] = dp[i-1]+1;
        }
        for (int i = 0; i < p.size(); i++)
            cnt[p[i]-'a'] = max(cnt[p[i]-'a'], dp[i]);
        return accumulate(cnt.begin(), cnt.end(), 0);
    }
};

int main() {
    return 0;
}
