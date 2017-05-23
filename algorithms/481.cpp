#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        vector<int> s = {1, 2, 2};
        for (int i = 2; s.size() < n; i++) {
            vector<int> t(s[i], s.back()%2+1);
            s.insert(s.end(), t.begin(), t.end());
        }
        return count(s.begin(), s.begin()+n, 1);
    }
};

int main() {
    return 0;
}
