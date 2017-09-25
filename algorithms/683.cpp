#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int kEmptySlots(vector<int> &flowers, int k) {
        vector<int> slots(flowers.size());
        for (int i = 0; i < flowers.size(); i++)
            slots[flowers[i]-1] = i+1;
        int left = 0, right = k+1;
        int result = INT32_MAX;
        for (int i = 0; right < slots.size(); i++) {
            if (slots[i] < slots[left] || slots[i] <= slots[right]) {
                if (i == right)
                    result = min(result, max(slots[left], slots[right]));
                left = i, right = i+k+1;
            }
        }
        return result==INT32_MAX ? -1 : result;
    }
};

int main() {
    return 0;
}
