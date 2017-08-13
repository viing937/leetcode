#include <iostream>
using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int n = s.size(), result = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') continue;
            while (i+1 < n && s[i+1] != ' ') i++;
            result += 1;
        }
        return result;
    }
};

int main() {
    return 0;
}
