#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    vector<int> pow2 = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512
                       , 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288
                       , 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912
                       , 1073741824};
    unordered_map<int, unordered_map<int, int>> cache;
    int binLen(int num) {
        int len = 0;
        while (num) {
            num = num>>1;
            len += 1;
        }
        return len;
    }
    int helper(int n, int limit) {
        if (n == 0)
            return 1;
        if (n == 1)
            return limit==0 ? 1 : 2;
        limit = min(limit, pow2[n]-1);
        if (cache[n].find(limit) != cache[n].end())
            return cache[n][limit];
        int result = helper(n-1, limit);
        if (pow2[n-1] <= limit) {
            result += helper(n-2, limit-pow2[n-1]);
        }
        cache[n][limit] = result;
        return result;
    }
public:
    int findIntegers(int num) {
        int len = binLen(num);
        return helper(len, num);
    }
};

int main() {
    Solution solution;
    cout << solution.findIntegers(1000000000) << endl;
    return 0;
}
