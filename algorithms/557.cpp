#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        for (auto it = s.begin(); it != s.end();) {
            auto found = find(it, s.end(), ' ');
            reverse(it, found);
            it = found!=s.end() ? found+1 : found;
        }
        return s;
    }
};

int main() {
    Solution solution;
    solution.reverseWords("Let's take LeetCode contest");
    return 0;
}
