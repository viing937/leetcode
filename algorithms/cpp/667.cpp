#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> arr(n);
        arr[0] = 1;
        for (int i = 1; i < n; i++) {
            if (i <= k)
                arr[i] = arr[i-1] + (i%2 ? 1 : -1) * (k-i+1);
            else
                arr[i] = i+1;
        }
        return arr;
    }
};

int main() {
    return 0;
}
