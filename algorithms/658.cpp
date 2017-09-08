#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int n = arr.size();
        if (n == 0 || k == 0) return vector<int>();
        if (arr[0] > x) return vector<int>(arr.begin(), arr.begin()+k);
        int i = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int j = i+1;
        if (i != 0 && abs(arr[i-1]-x) < abs(arr[i]-x))
            i -= 1, j -= 1;
        while (--k) {
            if (i == 0) {j++; continue;}
            i -= 1;
            if (j < n && abs(arr[i]-x) > abs(arr[j]-x))
                i += 1, j += 1;
        }
        return vector<int>(arr.begin()+i, arr.begin()+j);
    }
};

int main() {
    return 0;
}
