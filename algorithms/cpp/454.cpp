#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D) {
        int n = A.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                m[A[i]+B[j]] += 1;
        int result = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                result += m[-C[i]-D[j]];
        return result;
    }
};

int main() {
    return 0;
}
