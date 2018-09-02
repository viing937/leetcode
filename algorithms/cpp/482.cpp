#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        S.erase(remove(S.begin(), S.end(), '-'), S.end());
        int n = S.size();
        string result;
        for (int i = 0; i < S.size(); i++) {
            if (i != 0 && (n-i) % K == 0) result.push_back('-');
            result.push_back(toupper(S[i]));
        }
        return result;
    }
};

int main() {
    return 0;
}
