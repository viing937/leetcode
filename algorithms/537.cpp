#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
private:
    pair<int, int> parse(const string &num) {
        int sep = num.find("+");
        return make_pair(atoi(num.substr(0).c_str()), atoi(num.substr(sep+1).c_str()));
    }

    pair<int, int> multiply(const pair<int, int> &a, const pair<int, int> &b) {
        return make_pair(a.first*b.first - a.second*b.second, a.first*b.second + a.second*b.first);
    }
public:
    string complexNumberMultiply(string a, string b) {
        pair<int, int> result = multiply(parse(a), parse(b));
        return to_string(result.first) + "+" + to_string(result.second) + "i";
    }
};

int main() {
    Solution solution;
    solution.complexNumberMultiply("1+1i", "1+-1i");
    return 0;
}
