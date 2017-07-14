#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stringstream ss;
        int i = 0;
        while (i < s.size()) {
            if (s[i] >= '0' && s[i] <= '9') {
                int j = i;
                while (s[j] >= '0' && s[j] <= '9')
                    j += 1;
                int times = stoi(s.substr(i, j-i));
                int stack = 0, start = j+1;
                do {
                    if (s[j] == '[')
                        stack += 1;
                    else if (s[j] == ']')
                        stack -= 1;
                    j += 1;
                } while (stack > 0);
                string sub = decodeString(s.substr(start, j-start-1));
                while (times--)
                    ss << sub;
                i = j;
            }
            else
                ss << s[i++];
        }
        return ss.str();
    }
};

int main() {
    return 0;
}
