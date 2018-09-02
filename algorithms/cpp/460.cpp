#include <iostream>
#include <list>
#include <unordered_map>
#include <map>
using namespace std;

class LFUCache {
private:
    int capacity;
    map<int, list<pair<int, int>>> cache;
    unordered_map<int, int> keyToFre;
    unordered_map<int, list<pair<int, int>>::iterator> keyToIter;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    int get(int key) {
        if (keyToFre.find(key) == keyToFre.end()) return -1;
        int val = keyToIter[key]->second;
        int fre = keyToFre[key];
        cache[fre].erase(keyToIter[key]);
        if (cache[fre].empty()) cache.erase(fre);
        keyToFre[key] = fre+1;
        cache[fre+1].emplace_back(key, val);
        keyToIter[key] = --cache[fre+1].end();
        return val;
    }
    void put(int key, int value) {
        if (keyToFre.find(key) != keyToFre.end()) {
            keyToIter[key]->second = value;
            get(key);
            return;
        }
        if (capacity <= 0) {
            if (cache.empty()) return;
            int toEvicted = cache.begin()->second.begin()->first;
            cache.begin()->second.erase(keyToIter[toEvicted]);
            if (cache.begin()->second.empty()) cache.erase(cache.begin());
            keyToFre.erase(toEvicted);
            keyToIter.erase(toEvicted);
        } else {
            capacity -= 1;
        }
        keyToFre[key] = 1;
        cache[1].emplace_back(key, value);
        keyToIter[key] = --cache[1].end();
    }
};

int main() {
    return 0;
}
