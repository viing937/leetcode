#include <iostream>
#include <cmath>
using namespace std;

class Solution {
private:
    long n, diff, result;
    void update(long pal) {
        if (pal == n)
            return;
        if (abs(pal- n) < diff || (abs(pal-n) == diff && pal < result)) {
            diff = abs(pal-n);
            result = pal;
        }
    }
public:
    string nearestPalindromic(string n) {
        this->n = stoll(n);
        this->diff = LONG_MAX;

        update((long)pow(10, n.size())+1);
        update((long)pow(10, n.size()-1)-1);

        long halfLeft = stol(n.substr(0, (n.size()+1)/2));
        for (int i = -1; i <= 1; i++) {
            string prefix = to_string(halfLeft+i);
            string suffix = string(prefix.rbegin()+(n.size()%2), prefix.rend());
            update(stol(prefix+suffix));
        }

        return to_string(this->result);
    }
};

int main() {
    Solution solution;
    solution.nearestPalindromic("1");
    return 0;
}
