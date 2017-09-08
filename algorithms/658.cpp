#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        auto compare  = [&x](const int &a, const int &b) {
            return !(abs(a-x) < abs(b-x) || abs(a-x) == abs(b-x) && a < b);
        };
        priority_queue<int, vector<int>, decltype(compare)> pq(compare, arr);
        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            result[i] = pq.top();
            pq.pop();
        }
        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    return 0;
}
