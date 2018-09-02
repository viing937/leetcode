#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int, bool> m;
    bool helper(int state, int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0)
            return false;
        if (m.find(state) != m.end())
            return m[state];
        for (int i = 1; i <= maxChoosableInteger; i++) {
            if ((state>>i)&1)
                continue;
            int newState = state|(1<<i);
            if (!helper(newState, maxChoosableInteger, desiredTotal-i)) {
                m[state] = true;
                return m[state];
            }
        }
        m[state] = false;
        return m[state];
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((maxChoosableInteger+1) * maxChoosableInteger / 2 < desiredTotal)
            return false;
        if (desiredTotal <= 0)
            return true;
        m.clear();
        return helper(0, maxChoosableInteger, desiredTotal);
    }
};

int main() {
    return 0;
}
