#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int> &nums) {
        unordered_map<int, int> freq, appendFreq;
        for (auto num: nums) freq[num] += 1;
        for (auto num: nums) {
            if (freq[num] == 0) continue;
            if (appendFreq[num] > 0) {
                appendFreq[num] -= 1;
                appendFreq[num+1] += 1;
            }
            else if (freq[num+1] > 0 && freq[num+2] > 0) {
                freq[num+1] -= 1;
                freq[num+2] -= 1;
                appendFreq[num+3] += 1;
            }
            else return false;
            freq[num] -= 1;
        }
        return true;
    }
};

int main() {
    return 0;
}
