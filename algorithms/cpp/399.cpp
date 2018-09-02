#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double> &values, vector<pair<string, string>> queries) {
        map<string, map<string, double>> g;
        for (int i = 0; i < equations.size(); i++) {
            string &a = equations[i].first, &b = equations[i].second;
            double val = values[i];
            g[a][a] = g[b][b] = 1;
            g[a][b] = val;
            g[b][a] = 1/val;
        }
        for (auto kIter = g.begin(); kIter != g.end(); ++kIter) {
            const string &k = kIter->first;
            for (auto iIter = g[k].begin(); iIter != g[k].end(); ++iIter) {
                const string &i = iIter->first;
                for (auto jIter = g[k].begin(); jIter != g[k].end(); ++jIter) {
                    const string &j = jIter->first;
                    g[i][j] = g[i][k] * g[k][j];
                    g[j][i] = 1 / g[i][j];
                }
            }
        }
        vector<double> result(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            string &a = queries[i].first, &b = queries[i].second;
            result[i] = g[a].find(b) != g[a].end() ? g[a][b] : -1;
        }
        return result;
    }
};

int main() {
    return 0;
}
