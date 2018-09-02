#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int> &nums) {
        set<int> top3;
        for (auto num: nums) {
            if (top3.insert(num).second && top3.size() > 3)
                top3.erase(top3.begin());
        }
        return top3.size()==3 ? *top3.begin() : *top3.rbegin();
    }
};

int main() {
    return 0;
}
