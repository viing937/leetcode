#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int> &candies) {
        unordered_map<int, int> kindToCount;
        for (auto candy: candies)
            kindToCount[candy] += 1;
        return min(candies.size()/2, kindToCount.size());
    }
};

int main() {
    return 0;
}
