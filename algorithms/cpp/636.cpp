#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    void readLog(const string &log, int &id, string &status, int &timestamp) {
        string s;
        stringstream ss(log);
        getline(ss, s, ':'); id = stoi(s);
        getline(ss, status, ':');
        getline(ss, s, ':'); timestamp = stoi(s);
        return;
    }
public:
    vector<int> exclusiveTime(int n, vector<string> &logs) {
        vector<int> result(n, 0);
        int id, timestamp;
        string status;
        int prevTime;
        stack<int> func;
        for (const auto &log: logs) {
            readLog(log, id, status, timestamp);
            if (!func.empty())
                result[func.top()] += timestamp - prevTime;
            prevTime = timestamp;
            if (status == "start")
                func.push(id);
            else {
                result[func.top()] += 1;
                prevTime += 1;
                func.pop();
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
