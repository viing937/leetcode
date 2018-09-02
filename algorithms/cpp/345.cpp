#include <iostream>
using namespace std;

class Solution {
private:
    bool isVowel(char c) {
        if (c >= 'A' && c <= 'Z')
            c = c-'A'+'a';
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    string reverseVowels(string s) {
        if (s.size() == 0)
            return s;
        int left = 0, right = s.size()-1;
        while (left < right) {
            while (left < right && !isVowel(s[left])) left += 1;
            while (left < right && !isVowel(s[right])) right -= 1;
            swap(s[left++], s[right--]);
        }
        return s;
    }
};

int main() {
    return 0;
}
