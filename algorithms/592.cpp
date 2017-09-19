#include <iostream>
#include <sstream>
using namespace std;

class Solution {
private:
    int gcd(int a, int b) {
        int t;
        a = abs(a), b = abs(b);
        while (b) {
            t = a;
            a = b;
            b = t%b;
        }
        return a;
    }
    pair<int, int> fractionAdd(pair<int, int> &a, pair<int, int> &b) {
        pair<int, int> c = make_pair(a.first * b.second + a.second * b.first, a.second * b.second);
        int d = gcd(c.first, c.second);
        c.first /= d; c.second /= d;
        return c;
    }
public:
    string fractionAddition(string expression) {
        stringstream ss(expression);
        char ch;
        pair<int, int> result, num;
        ss >> result.first >> ch >> result.second;
        while (ss >> num.first) {
            ss >> ch >> num.second;
            result = fractionAdd(result, num);
        }
        return to_string(result.first) + "/" + to_string(result.second);
    }
};

int main() {
    return 0;
}
