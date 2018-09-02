#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int result = 0, i, j;
        for (i = 0, j = 0; i < g.size(); i++, j++) {
            while (j < s.size() && g[i] > s[j])
                j += 1;
            if (j < s.size())
                result += 1;
        }
        return result;
    }
};

int main() {
    return 0;
}
