#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    static bool compare(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    }
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people) {
        int n = people.size();
        sort(people.begin(), people.end(), compare);
        for (int i = 0; i < n; i++) {
            pair<int, int> v = people[i];
            for (int j = i-1; j >= v.second; j--)
                people[j+1] = people[j];
            people[v.second] = v;
        }
        return people;
    }
};

int main() {
    vector<pair<int, int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    Solution solution;
    solution.reconstructQueue(people);
    return 0;
}
