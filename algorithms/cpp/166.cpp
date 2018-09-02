#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(long numerator, long denominator) {
        if (numerator == 0)
            return "0";
        string result;
        if (numerator < 0 ^ denominator < 0)
            result += "-";
        numerator = abs(numerator);
        denominator = abs(denominator);
        result += to_string(numerator/denominator);
        numerator %= denominator;
        if (numerator == 0)
            return result;
        result += ".";
        unordered_map<long, int> m;
        while (numerator) {
            if (m.find(numerator) == m.end()) {
                m[numerator] = result.size();
                numerator *= 10;
                result += to_string(numerator/denominator);
                numerator %= denominator;
            }
            else {
                result.insert(m[numerator], 1, '(');
                result.insert(result.end(), 1, ')');
                break;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
