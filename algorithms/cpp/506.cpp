#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    static bool compare(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first > b.first;
    }
public:
    vector<string> findRelativeRanks(vector<int> &nums) {
        vector<pair<int, int>> p;
        for (int i = 0; i < nums.size(); i++)
            p.push_back(make_pair(nums[i], i));
        sort(p.begin(), p.end(), compare);
        vector<string> result(nums.size());
        for (int i = 0; i < p.size(); i++) {
            if (i == 0)
                result[p[i].second] = "Gold Medal";
            else if (i == 1)
                result[p[i].second] = "Silver Medal";
            else if (i == 2)
                result[p[i].second] = "Bronze Medal";
            else
                result[p[i].second] = to_string(i+1);
        }
        return result;
    }
};

int main() {
    return 0;
}
