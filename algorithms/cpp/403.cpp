#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int, unordered_map<int, bool>> m;
    unordered_map<int, int> s;
    bool helper(const vector<int> &stones, int pos, int jump) {
        if (pos+1 == stones.size())
            return true;
        if (m.find(pos) != m.end() && m[pos].find(jump) != m[pos].end())
            return m[pos][jump];
        bool result = false;
        for (int i = jump-1; i <= jump+1; i++) {
            if (i <= 0)
                continue;
            if (s.find(stones[pos]+i) != s.end())
                result = result || helper(stones, s[stones[pos]+i], i);
        }
        m[pos][jump] = result;
        return result;
    }
public:
    bool canCross(vector<int> &stones) {
        if (stones.size() == 1)
            return true;
        if (stones[1] - stones[0] != 1)
            return false;
        s.clear(), m.clear();
        for (int i = 0; i < stones.size(); i++)
            s[stones[i]] = i;
        return helper(stones, 1, 1);
    }
};

int main() {
    vector<int> stones = {0,1,3,4,5,7,9,10,12};
    Solution solution;
    solution.canCross(stones);
    return 0;
}
