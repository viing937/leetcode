#include <iostream>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int n = s.size();
        int cntA = 0, cntL = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                cntA += 1;
                if (cntA > 1) return false;
            }
            if (s[i] == 'L') {
                cntL += 1;
                if (cntL > 2) return false;
            }
            else
                cntL = 0;
        }
        return true;
    }
};

int main() {
    return 0;
}
