#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    const string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int base = chars.size();
    vector<string> urls;

    string URLencode(int x) {
        string s;
        while (x) {
            s.push_back(chars[x%base]);
            x /= base;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    int URLdecode(const string &s) {
        int x = 0;
        for (auto ch: s) {
            x *= base;
            if (ch >= '0' && ch <= '9')
                x += ch-'0';
            else if (ch >= 'a' && ch <= 'z')
                x += ch-'a'+10;
            else
                x += ch-'A'+36;
        }
        return x;
    }
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        urls.push_back(longUrl);
        return "http://tinyurl.com/" + URLencode(urls.size()-1);
    }
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return urls[URLdecode(shortUrl.substr(1+shortUrl.find_last_of("/")))];
    }
};

int main() {
    Solution solution;
    cout << solution.decode(solution.encode("https://leetcode.com/problems/design-tinyurl")) << endl;
    return 0;
}
