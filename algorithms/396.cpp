#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxRotateFunction(vector<int> &A) {
        int s = 0, t = 0;
        for (int i = 0; i < A.size(); i++) {
            s += A[i];
            t += i*A[i];
        }
        int result = t;
        for (int i = A.size()-1; i >= 1; i--) {
            t = t + s - A[i]*A.size();
            result = max(result, t);
        }
        return result;
    }
};

int main() {
    return 0;
}
