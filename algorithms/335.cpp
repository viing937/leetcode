#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int> &x) {
        int n = x.size();
        for (int i = 0; i < n; i++) {
            if (i >= 3 && x[i] >= x[i-2] && x[i-1] <= x[i-3]) return true;
            if (i >= 4 && x[i-1] == x[i-3] && x[i] >= x[i-2]-x[i-4]) return true;
            if (i >= 5 && x[i-2] > x[i-4] && x[i-1] >= x[i-3]-x[i-5] && x[i-1] <= x[i-3] && x[i] >= x[i-2]-x[i-4]) return true;
        }
        return false;
    }
};

int main() {
    return 0;
}
