#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> result;
    vector<long long> sign;
    vector< vector<long long> > nums;

    void dfs(const string &num, int pos, long long target, long long sum, long long product) {
        if (pos >= num.size() && sum + product == target) {
            result.push_back("");
            int n = nums.size();
            for (int i = 0; i < n; i++) {
                if (i != 0)
                    result.back() += (sign[i]>0?"+":"-") + to_string(nums[i][0]);
                else
                    result.back() += to_string(nums[i][0]);

                for (int j = 1; j < nums[i].size(); j++)
                    result.back() += "*" + to_string(nums[i][j]);
            }
            return;
        }
        for (int i = pos+1; i <= num.size(); i++) {
            string t = num.substr(pos, i-pos);
            long long now = atol(t.c_str());
            if (to_string(now).size() != t.size())
                break;

            // +
            nums.push_back(vector<long long>(1, now));
            sign.push_back(1);
            dfs(num, i, target, sum+product, now);
            nums.pop_back();
            sign.pop_back();

            if (nums.size() == 0)
                continue;

            // -
            nums.push_back(vector<long long>(1, now));
            sign.push_back(-1);
            dfs(num, i, target, sum+product, -now);
            nums.pop_back();
            sign.pop_back();

            // *
            nums.back().push_back(now);
            dfs(num, i, target, sum, product*now);
            nums.back().pop_back();
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        result.clear();
        sign.clear();
        nums.clear();

        dfs(num, 0, target, 0, 0);

        return result;
    }
};

int main() {
    Solution solution;
    solution.addOperators("123", 6);
    return 0;
}
