#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int, int> dp;
    int get(int needs, int k) {
        return (needs>>(k*4)) & 0xf;
    }
    int put(int needs, int k, int val) {
        needs &= ~(0xf<<(4*k));
        needs |= val<<(4*k);
        return needs;
    }
    int helper(int needs, const vector<vector<int>> &special) {
        int n = special[0].size()-1;
        if (needs == 0)
            return 0;
        if (dp.find(needs) != dp.end())
            return dp[needs];
        int result = INT_MAX;
        for (int i = 0; i < special.size(); i++) {
            bool isNeed = true;
            int newNeeds = needs;
            for (int j = 0; j < n; j++) {
                int num = get(newNeeds, j);
                if (num - special[i][j] < 0) {
                    isNeed = false;
                    break;
                }
                newNeeds = put(newNeeds, j, num-special[i][j]);
            }
            if (!isNeed) continue;
            result = min(result, helper(newNeeds, special) + special[i].back());
        }
        dp[needs] = result;
        return result;
    }
public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs) {
        int t = 0;
        for (int i = 0; i < needs.size(); i++)
            t = put(t, i, needs[i]);
        for (int i = 0; i < price.size(); i++) {
            special.emplace_back(price.size()+1, 0);
            special.back()[i] = 1;
            special.back().back() = price[i];
        }
        return helper(t, special);
    }
};

int main() {
    vector<int> price = {2, 5};
    vector<vector<int>> special = {{3, 0, 5}, {1, 2, 10}};
    vector<int> needs{3, 2};
    Solution solution;
    cout << solution.shoppingOffers(price, special, needs) << endl;
    return 0;
}
