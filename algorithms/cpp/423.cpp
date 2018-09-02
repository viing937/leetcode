#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(10);
        for (auto ch: s) {
            if (ch == 'z') count[0]++;
            if (ch == 'w') count[2]++;
            if (ch == 'x') count[6]++;
            if (ch == 's') count[7]++; //7-6
            if (ch == 'g') count[8]++;
            if (ch == 'u') count[4]++;
            if (ch == 'f') count[5]++; //5-4
            if (ch == 'h') count[3]++; //3-8
            if (ch == 'i') count[9]++; //9-8-5-6
            if (ch == 'o') count[1]++; //1-0-2-4
        }
        count[7] -= count[6];
        count[5] -= count[4];
        count[3] -= count[8];
        count[9] = count[9] - count[8] - count[5] - count[6];
        count[1] = count[1] - count[0] - count[2] - count[4];

        string result;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < count[i]; j++)
                result.push_back('0'+i);

        return result;
    }
};

int main() {
    return 0;
}
