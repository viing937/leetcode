#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void helper(int N, int pos, vector<int> &used, int &count) {
        if (pos == N+1)
            count += 1;
        for (int i = 1; i <= N; i++) {
            if (used[i])
                continue;
            if (pos%i && i%pos)
                continue;
            used[i] = 1;
            helper(N, pos+1, used, count);
            used[i] = 0;
        }
    }
public:
    int countArrangement(int N) {
        vector<int> used(N+1, 0);
        int count = 0;
        helper(N, 1, used, count);
        return count;
    }
};

int main() {
    return 0;
}
