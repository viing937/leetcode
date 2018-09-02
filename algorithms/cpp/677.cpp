#include <iostream>
#include <unordered_map>
using namespace std;

class MapSum {
private:
    unordered_map<string, int> m;
    unordered_map<string, int> prefixSum;
public:
    /** Initialize your data structure here. */
    MapSum() {
    }

    void insert(string key, int val) {
        int diff = val - m[key];
        m[key] = val;
        for (int i = 1; i <= key.size(); i++)
            prefixSum[key.substr(0, i)] += diff;
        return;
    }

    int sum(string prefix) {
        return prefixSum[prefix];
    }
};

int main() {
    return 0;
}
