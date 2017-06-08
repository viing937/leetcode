#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    void escapeCDATA(string &code) {
        int pos = code.find("<![CDATA[");
        while (pos != string::npos) {
            int close = code.find("]]>", pos);
            if (close == string::npos)
                return;
            code.replace(pos, close-pos+3, "CDATA");
            pos = code.find("<![CDATA[");
        }
        return;
    }
    bool isValidTagName(const string &tag) {
        if (tag.size() < 1 || tag.size() > 9)
            return false;
        for (auto ch: tag)
            if (ch < 'A' || ch > 'Z')
                return false;
        return true;
    }
public:
    bool isValid(string code) {
        escapeCDATA(code);
        if (code.size() == 0 || code[0] != '<' || code.back() != '>')
            return false;

        int pos = 0;
        bool isClosed = false;
        stack<string> tags;
        while (pos < code.size()) {
            if (isClosed)
                return false;
            if (code[pos] != '<') {
                pos += 1;
                continue;
            }
            int close = code.find('>', pos);
            if (close == string::npos)
                return false;
            if (code[pos+1] != '/') {
                string tag = code.substr(pos+1, close-pos-1);
                if (!isValidTagName(tag))
                    return false;
                tags.push(tag);
            }
            else {
                string tag = code.substr(pos+2, close-pos-2);
                if (tags.empty() || tags.top() != tag)
                    return false;
                tags.pop();
                isClosed = tags.empty() ? true : false;
            }
            pos = close + 1;
        }
        return isClosed;
    }
};

int main() {
    Solution solution;
    solution.isValid("<TRUE><![CDATA[wahaha]]]><![CDATA[]> wahaha]]></TRUE>");
    return 0;
}
