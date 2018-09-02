#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> R, D;
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') R.push(i);
            if (senate[i] == 'D') D.push(i);
        }
        while (!R.empty() && !D.empty()) {
            if (R.front() < D.front())
                R.push(R.front() + n);
            else
                D.push(D.front() + n);
            R.pop();
            D.pop();
        }
        return R.empty() ? "Dire" : "Radiant";
    }
};

int main() {
    return 0;
}
