#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMinMoves(vector<int> &machines) {
        long long n = machines.size();
        vector<long long> sum(n+1, 0);
        for (long long i = 0; i < n; i++)
            sum[i+1] = sum[i] + machines[i];

        if (sum.back() % n)
            return -1;

        long long avg = sum.back() / n;
        long long result = 0;
        for (long long i = 0; i < n; i++) {
            long long l = sum[i] - i*avg, r = (sum.back()-sum[i+1]) - (n-i-1)*avg;
            if (l < 0 && r < 0)
                result = max(result, abs(l)+abs(r));
            else
                result = max(result, max(abs(l), abs(r)));
        }
        return result;
    }
};

int main() {
    return 0;
}
