#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        result.reserve(n);
        int num = 1;
        for (int i = 1; i <= n; i++) {
            result.push_back(num);
            if (num*10 <= n)
                num *= 10;
            else if (num%10 != 9 && num+1 <= n)
                num += 1;
            else {
                num /= 10;
                while (num%10 == 9)
                    num /= 10;
                num += 1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    solution.lexicalOrder(200);
    return 0;
}
