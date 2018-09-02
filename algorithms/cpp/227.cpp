#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stringstream ss(s);
        int totalSum = 0, part = 0, num;
        char ch;
        ss >> part;
        while (ss >> ch) {
            switch (ch) {
                case ' ':
                    break;
                case '+':
                    totalSum += part;
                    ss >> part;
                    break;
                case '-':
                    totalSum += part;
                    ss >> part;
                    part = -part;
                    break;
                case '*':
                    ss >> num;
                    part *= num;
                    break;
                case '/':
                    ss >> num;
                    part /= num;
                    break;
            }
        }
        return totalSum + part;
    }
};

int main() {
    return 0;
}
