#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> hash;

    void touch(int key) {
        auto it = hash[key];
        cache.push_front(*it);
        cache.erase(it);
        hash[key] = cache.begin();
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    int get(int key) {
        if (hash.find(key) == hash.end())
            return -1;
        touch(key);
        return cache.front().second;
    }
    void put(int key, int value) {
        if (hash.find(key) != hash.end()) {
            touch(key);
            cache.front().second = value;
        }
        else {
            cache.push_front(make_pair(key, value));
            hash[key] = cache.begin();
        }
        while (cache.size() > capacity) {
            hash.erase(cache.back().first);
            cache.pop_back();
        }
    }
};

int main() {
    return 0;
}
