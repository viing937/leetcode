#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool helper(const string &first, const string &second, const string &num) {
        string third = addString(first, second);
        if (num.find(third) == 0)
            return num.size() == third.size() ? true : helper(second, third, num.substr(third.size()));
        else
            return false;
    }
    string addString(const string &a, const string &b) {
        string c;
        int i = a.size()-1, j = b.size()-1;
        int carry = 0;
        while (i >= 0 && j >= 0)
            c.push_back(addChar(a[i--], b[j--], carry));
        while (i >= 0)
            c.push_back(addChar(a[i--], '0', carry));
        while (j >= 0)
            c.push_back(addChar('0', b[j--], carry));
        while (carry)
            c.push_back(addChar('0', '0', carry));
        return string(c.rbegin(), c.rend());
    }
    char addChar(char a, char b, int &carry) {
        int sum = (a-'0') + (b-'0') + carry;
        carry = sum / 10;
        return sum % 10 + '0';
    }
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int i = 1; i < n; i++) {
            for (int j = 1; i+j < n; j++) {
                if (num[i] == '0' && j != 1) continue;
                if (num[i+j] == '0' && n-i-j != 1) continue;
                if (helper(num.substr(0, i), num.substr(i, j), num.substr(i+j)))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    solution.isAdditiveNumber("111122335588143");
    return 0;
}
