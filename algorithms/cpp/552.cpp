#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int addmod(int a, int b = 0, int c = 0) {
        int mod = 1000000007;
        return ((a + b) % mod + c) % mod;
    }
public:
    int checkRecord(int n) {
        vector<vector<int>> AL(2, vector<int>(3, 0));
        vector<vector<int>> P(2, vector<int>(3)), L(2, vector<int>(3)), A(2, vector<int>(3));
        AL[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            P[0][0] = addmod(AL[0][0], AL[0][1], AL[0][2]);
            P[0][1] = 0;
            P[0][2] = 0;
            P[1][0] = addmod(AL[1][0], AL[1][1], AL[1][2]);
            P[1][1] = 0;
            P[1][2] = 0;

            L[0][0] = 0;
            L[0][1] = AL[0][0];
            L[0][2] = AL[0][1];
            L[1][0] = 0;
            L[1][1] = AL[1][0];
            L[1][2] = AL[1][1];

            A[0][0] = 0;
            A[0][1] = 0;
            A[0][2] = 0;
            A[1][0] = addmod(AL[0][0], AL[0][1], AL[0][2]);
            A[1][1] = 0;
            A[1][2] = 0;

            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 3; j++)
                    AL[i][j] = addmod(P[i][j], L[i][j], A[i][j]);
        }
        int result = 0;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                result = addmod(result, AL[i][j]);
        return result;
    }
};

int main() {
    return 0;
}
