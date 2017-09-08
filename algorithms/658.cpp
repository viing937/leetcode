#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int n = arr.size(), i, j;
        i = lower_bound(arr.begin(), arr.end(), x) - arr.begin() - 1, j = i+1;
        while (k--) {
            if (i < 0 || (j < n && abs(arr[i]-x) > abs(arr[j]-x)))
                j += 1;
            else
                i -= 1;
        }
        return vector<int>(arr.begin()+i+1, arr.begin()+j);
    }
};

int main() {
    return 0;
}
