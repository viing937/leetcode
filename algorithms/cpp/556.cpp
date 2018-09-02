#include <iostream>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        long result = -1;
        string num = to_string(n);
        for (int i = num.size()-1; i > 0; i--) {
            if (num[i-1] >= num[i])
                continue;
            for (int j = num.size()-1; j >= i; j--) {
                if (num[i-1] < num[j]) {
                    swap(num[i-1], num[j]);
                    break;
                }
            }
            sort(num.begin()+i, num.end());
            result = stol(num);
            result = result>INT_MAX ? -1 : result;
            break;
        }
        return result;
    }
};

int main() {
    return 0;
}
