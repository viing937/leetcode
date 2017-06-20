#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string> &paths) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> files;
        for (auto path: paths) {
            stringstream ss(path);
            string root;
            string s;
            getline(ss, root, ' ');
            while (getline(ss, s, ' ')) {
                string name = root + "/" + s.substr(0, s.find('('));
                string content = s.substr(s.find('(')+1); content.pop_back();
                files[content].push_back(name);
            }
        }
        for (auto p: files) {
            if (p.second.size() > 1)
                result.push_back(p.second);
        }
        return result;
    }
};

int main() {
    return 0;
}
