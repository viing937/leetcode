#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> valToIdx;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (valToIdx.find(val) != valToIdx.end()) return false;
        valToIdx[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (valToIdx.find(val) == valToIdx.end()) return false;
        int idx = valToIdx[val];
        nums[idx] = nums.back();
        valToIdx[nums.back()] = idx;
        nums.pop_back();
        valToIdx.erase(val);
        return true;
    }
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

int main() {
    return 0;
}
