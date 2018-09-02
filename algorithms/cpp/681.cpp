#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string nextClosestTime(string time) {
        vector<int> mins = {600, 60, 10, 1};
        int cur = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
        string next = "00:00";
        for (int i = 1, d = 0; i <= 1440 && d < 4; i++) {
            int m = (cur+i) % 1440;
            for (d = 0; d < 4; d++) {
                next[d] = '0' + m/mins[d];
                m %= mins[d];
                if (time.find(next[d]) == string::npos) break;
            }
        }
        return next.substr(0, 2) + ":" + next.substr(2, 2);
    }
};

int main() {
    return 0;
}
