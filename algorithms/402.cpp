#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int digits = num.size()-k;
        vector<char> s(num.size());
        int top = 0;
        for (int i = 0; i < num.size(); i++) {
            while (top > 0 && s[top-1] > num[i] && k > 0) {
                top -= 1;
                k -= 1;
            }
            s[top++] = num[i];
        }
        int idx = 0;
        while (idx < digits && s[idx] == '0') idx += 1;
        if (idx == digits) return "0";
        return string(s.begin()+idx, s.begin()+digits);
    }
};

int main() {
    Solution solution;
    cout << solution.removeKdigits("10", 1) << endl;
    return 0;
}
