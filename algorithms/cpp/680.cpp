#include <iostream>
using namespace std;

class Solution {
private:
    bool helper(string &s, int left, int right, bool modifiable) {
        while (left <= right && s[left] == s[right]) {
            left += 1;
            right -= 1;
        }
        if (left > right) return true;
        if (modifiable)
            return helper(s, left+1, right, false) || helper(s, left, right-1, false);
        return false;
    }
public:
    bool validPalindrome(string s) {
        return helper(s, 0, s.size()-1, true);
    }
};

int main() {
    return 0;
}
