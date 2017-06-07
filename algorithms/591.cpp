#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string code) {
        int pos;

        pos = code.find("<![CDATA[");
        while (pos != string::npos) {
            int close = code.find("]]>", pos);
            if (close == string::npos)
                return false;
            code.replace(pos, close-pos+3, "CDATA");
            pos = code.find("<![CDATA[");
        }

        if (code.size() == 0 || code[0] != '<' || code.back() != '>')
            return false;

        pos = 0;
        stack<string> tags;
        int cnt = 0;
        while (pos < code.size()) {
            if (cnt == 1)
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
                if (tag.size() < 1 || tag.size() > 9)
                    return false;
                for (auto ch: tag)
                    if (ch < 'A' || ch > 'Z')
                        return false;
                tags.push(tag);
            }
            else {
                string tag = code.substr(pos+2, close-pos-2);
                if (tags.empty() || tags.top() != tag)
                    return false;
                tags.pop();
                cnt += tags.empty() ? 1 : 0;
            }
            pos = close + 1;
        }
        return cnt==1 ? true : false;
    }
};

int main() {
    Solution solution;
    solution.isValid("<TRUE><![CDATA[wahaha]]]><![CDATA[]> wahaha]]></TRUE>");
    return 0;
}
