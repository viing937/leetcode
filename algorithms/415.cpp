#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    char addChar(char c1, char c2, int &c) {
        int a = c1 - '0', b = c2 - '0';
        int s = (a+b+c) % 10;
        c = (a+b+c) / 10;
        return s + '0';
    }
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string result;
        int idx = 0, c = 0;
        while (idx < num1.size() && idx < num2.size()) {
            result.push_back(addChar(num1[idx], num2[idx], c));
            idx += 1;
        }
        while (idx < num1.size()) {
            result.push_back(addChar(num1[idx], '0', c));
            idx += 1;
        }
        while (idx < num2.size()) {
            result.push_back(addChar('0', num2[idx], c));
            idx += 1;
        }
        if (c)
            result.push_back(addChar('0', '0', c));
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    return 0;
}
