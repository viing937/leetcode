#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        int result = 0;
        int accuLength = 0;
        string dir;
        vector<string> dirVector;
        stringstream ss(input);
        while (getline(ss, dir, '\n')) {
            int depth = 0;
            while (dir[depth] == '\t')
                depth += 1;
            dir = dir.substr(depth);
            while (dirVector.size() > depth) {
                accuLength -= dirVector.back().size();
                dirVector.pop_back();
            }
            if (dir.find('.') != string::npos)
                result = max(result, accuLength + (int)dir.size() + (int)dirVector.size());
            else {
                accuLength += dir.size();
                dirVector.push_back(dir);
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
