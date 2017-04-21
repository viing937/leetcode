#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<string> result;

    void dfs(const string &num, int pos, long long target, string cur, long long sum, long long product) {
        if (pos >= num.size() && sum + product == target) {
            result.push_back(cur.substr(1));
            return;
        }
        for (int i = pos+1; i <= num.size(); i++) {
            string t = num.substr(pos, i-pos);
            long long now = atol(t.c_str());
            if (to_string(now).size() != t.size())
                break;

            // +
            dfs(num, i, target, cur + "+" + t, sum+product, now);

            if (pos == 0)
                continue;

            // -
            dfs(num, i, target, cur + "-" + t, sum+product, -now);

            // *
            dfs(num, i, target, cur + "*" + t, sum, product*now);
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        result.clear();

        dfs(num, 0, target, "", 0, 0);

        return result;
    }
};

int main() {
    Solution solution;
    solution.addOperators("123", 6);
    return 0;
}
