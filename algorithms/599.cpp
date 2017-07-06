#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
        unordered_map<string, int> p;
        for (int i = 0; i < list1.size(); i++)
            p[list1[i]] = i;
        int minSum = INT_MAX;
        vector<string> result;
        for (int i = 0; i < list2.size(); i++) {
            if (p.find(list2[i]) == p.end())
                continue;
            int newSum = p[list2[i]] + i;
            if (newSum > minSum)
                continue;
            if (newSum < minSum) {
                minSum = newSum;
                result.clear();
            }
            result.push_back(list2[i]);
        }
        return result;
    }
};

int main() {
    return 0;
}
