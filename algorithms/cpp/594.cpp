#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findLHS(vector<int> &nums) {
        unordered_map<int, int> m;
        for (auto num: nums)
            m[num] += 1;
        int result = 0;
        for (auto &p: m) {
            if (m.find(p.first+1) != m.end())
                result = max(result, p.second + m[p.first+1]);
        }
        return result;
    }
};

int main() {
    return 0;
}
