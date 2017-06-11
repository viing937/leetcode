#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
private:
    string helper(const vector<string> &line, int length, int maxWidth, bool isLast) {
        int nspace, ext;
        if (line.size() == 1 || isLast) {
            nspace = 1;
            ext = 0;
        }
        else {
            nspace = (maxWidth-length) / (line.size()-1);
            ext = (maxWidth-length) % (line.size()-1);
        }
        stringstream ss;
        for (int i = 0; i < line.size(); i++) {
            ss << line[i];
            if (i != line.size()-1) {
                for (int j = 0; j < nspace; j++)
                    ss << " ";
                if (i < ext)
                    ss << " ";
            }
        }
        string result = ss.str();
        while (result.size() < maxWidth)
            result.push_back(' ');
        return result;
    }
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> result;
        vector<string> line;
        int length = 0;
        for (auto word: words) {
            if (word.size() + length + line.size() > maxWidth) {
                result.push_back(helper(line, length, maxWidth, false));
                line.clear();
                length = 0;
            }
            line.push_back(word);
            length += word.size();
        }
        if (line.size() > 0)
            result.push_back(helper(line, length, maxWidth, true));
        return result;
    }
};

int main() {
    return 0;
}
