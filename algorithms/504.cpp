#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";

        string result;

        if (num < 0) {
            result.push_back('-');
            num = abs(num);
        }

        while (num) {
            result.push_back(num%7+'0');
            num /= 7;
        }

        if (result[0] == '-')
            reverse(result.begin()+1, result.end());
        else
            reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    return 0;
}
