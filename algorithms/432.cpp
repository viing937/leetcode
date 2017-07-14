#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

class AllOne {
private:
    unordered_map<string, int> keyToVal;
    map<int, set<string>> valToKey;
public:
    /** Initialize your data structure here. */
    AllOne() {
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        valToKey[keyToVal[key]].erase(key);
        if (valToKey[keyToVal[key]].empty())
            valToKey.erase(keyToVal[key]);
        if (keyToVal.find(key) == keyToVal.end())
            keyToVal[key] = 1;
        else
            keyToVal[key] += 1;
        valToKey[keyToVal[key]].insert(key);
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (keyToVal.find(key) == keyToVal.end())
            return;
        valToKey[keyToVal[key]].erase(key);
        if (valToKey[keyToVal[key]].empty())
            valToKey.erase(keyToVal[key]);
        if (keyToVal[key] == 1)
            keyToVal.erase(key);
        else {
            keyToVal[key] -= 1;
            valToKey[keyToVal[key]].insert(key);
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (valToKey.empty())
            return "";
        return *(valToKey.rbegin()->second).begin();
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (valToKey.empty())
            return "";
        return *(valToKey.begin()->second).begin();
    }
};

int main() {
    AllOne allOne;
    allOne.inc("a");
    allOne.inc("b");
    allOne.inc("b");
    allOne.inc("b");
    allOne.inc("b");
    allOne.dec("b");
    allOne.dec("b");
    cout << allOne.getMaxKey() << endl;
    cout << allOne.getMinKey() << endl;
    return 0;
}
