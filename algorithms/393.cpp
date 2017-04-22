#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validUtf8(vector<int> &data) {
        int n = data.size();

        for (int i = 0; i < n; i++) {
            int idx = -1;

            for (int j = 0; j < 8; j++) {
                if ((data[i] & (0x80>>j)) == 0x00) {
                    idx = j;
                    break;
                }
            }

            if (idx < 0 || idx == 1 || idx > 4)
                return false;

            if (idx == 0)
                continue;

            for (int j = 1; j < idx; j++) {
                if ((data[i+j] & 0x80) != 0x80)
                    return false;
            }

            i += idx-1;
        }

        return true;
    }
};

int main() {
    vector<int> data = {197,130,1};
    Solution solution;
    solution.validUtf8(data);
    return 0;
}
