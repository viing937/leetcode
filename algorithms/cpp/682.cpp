#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int calPoints(vector<string> &ops) {
        int result = 0;
        vector<int> scores;
        for (auto &op: ops) {
            if (op == "+") {
                scores.push_back(scores.back() + scores[scores.size()-2]);
                result += scores.back();
            }
            else if (op == "D") {
                scores.push_back(scores.back() * 2);
                result += scores.back();
            }
            else if (op == "C") {
                result -= scores.back();
                scores.pop_back();
            }
            else {
                scores.push_back(stoi(op));
                result += scores.back();
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
