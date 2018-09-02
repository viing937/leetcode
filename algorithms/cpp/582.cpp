#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution { 
private:
    void helper(int kill, unordered_map<int, vector<int>> &child, vector<int> &result) {
        for (int i = 0; i < child[kill].size(); i++)
            helper(child[kill][i], child, result);
        result.push_back(kill);
    }
public:
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
        unordered_map<int, vector<int>> child;
        for (int i = 0; i < pid.size(); i++)
            child[ppid[i]].push_back(pid[i]);
        vector<int> result;
        helper(kill, child, result);
        return result;
    }
};

int main() {
    return 0;
}
