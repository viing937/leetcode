#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> frequencyMap;

        for (auto num : nums)
            frequencyMap[num] += 1;

        vector< vector<int> > bucket(nums.size()+1);
        for (auto it = frequencyMap.begin(); it != frequencyMap.end(); ++it)
            bucket[it->second].push_back(it->first);

        vector<int> result;
        for (int i = nums.size(); i > 0 && result.size() < k; --i) {
            result.insert(result.begin(), bucket[i].begin(), bucket[i].end());
        }
        return result;
    }
};

int main() {
    return 0;
}
