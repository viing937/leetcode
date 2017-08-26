#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class RandomizedCollection {
private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> valToIdx;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
    }
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool contain = valToIdx.find(val) != valToIdx.end();
        valToIdx[val].insert(nums.size());
        nums.push_back(val);
        return !contain;
    }
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (valToIdx.find(val) == valToIdx.end()) return false;
        int idx = *valToIdx[val].begin();
        int lastVal = nums.back(), lastIdx = nums.size()-1;
        if (idx == lastIdx) {
            valToIdx[val].erase(idx);
            nums.pop_back();
        } else {
            valToIdx[lastVal].erase(lastIdx);
            nums.pop_back();
            valToIdx[val].erase(idx);
            valToIdx[lastVal].insert(idx);
            nums[idx] = lastVal;
        }
        if (valToIdx[val].empty()) valToIdx.erase(val);
        return true;
    }
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

int main() {
    return 0;
}
