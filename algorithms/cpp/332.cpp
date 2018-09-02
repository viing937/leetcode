#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
private:
    int target;
    vector<string> result;
    unordered_map<string, multiset<pair<string, int>>> graph;
    vector<bool> visited;

    bool dfs() {
        if (result.size() == target)
            return true;

        string cur = result.back();
        for (auto it = graph[cur].begin(); it != graph[cur].end(); ++it) {
            if (visited[it->second])
                continue;
            result.push_back(it->first);
            visited[it->second] = true;
            if (dfs())
                return true;
            visited[it->second] = false;
            result.pop_back();
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        target = tickets.size()+1;
        result = vector<string>(1, "JFK");

        visited = vector<bool>(tickets.size(), false);
        graph.clear();
        for (int i = 0; i < tickets.size(); i++)
            graph[tickets[i].first].insert(make_pair(tickets[i].second, i));

        dfs();
        return result;
    }
};

int main() {
    vector<pair<string, string>> tickets;
    tickets.push_back(make_pair("MUC","LHR"));
    tickets.push_back(make_pair("JFK","MUC"));
    tickets.push_back(make_pair("SFO","SJC"));
    tickets.push_back(make_pair("LHR","SFO"));
    Solution solution;
    solution.findItinerary(tickets);
    return 0;
}
