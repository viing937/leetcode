#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int result = 0;
        vector<int> chCount(26, 0);
        for (int i = 0, j = 0; j < s.size(); j++) {
            chCount[s[j]-'A'] += 1;
            while (*max_element(chCount.begin(), chCount.end()) + k < j-i+1)
                chCount[s[i++]-'A'] -= 1;
            result = max(result, j-i+1);
        }
        return result;
    }
};

int main() {
    return 0;
}
