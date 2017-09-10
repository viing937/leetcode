#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string snum = to_string(num);
        int n = snum.size();
        for (int i = 0; i < n; i++) {
            int t = n-1;
            for (int j = n-1; j > i; j--)
                if (snum[j] > snum[t])
                    t = j;
            if (snum[i] < snum[t]) {
                swap(snum[i], snum[t]);
                break;
            }
        }
        return stoi(snum);
    }
};

int main() {
    return 0;
}
