#include <iostream>
using namespace std;

class Solution {
public:
    string solveEquation(string equation) {
        int coefficient = 0, constant = 0;
        int isLeft = 1;
        int i = 0;
        while (i < equation.size()) {
            if (equation[i] == '=') {
                isLeft = -1; i += 1;
                continue;
            }
            int isPostive = equation[i]=='-' ? -1 : 1, val;
            i += (equation[i]=='-' || equation[i]=='+') ? 1 : 0;
            int j = i;
            while (j < equation.size() && equation[j] >= '0' && equation[j] <= '9')
                j += 1;
            val = equation[i]=='x' ? 1 : stoi(equation.substr(i, j-i));
            if (j < equation.size() && equation[j] == 'x') {
                coefficient += isLeft * isPostive * val;
                i = j+1;
            }
            else {
                constant += isLeft * isPostive * val;
                i = j;
            }
        }
        if (coefficient == 0)
            return constant == 0 ? "Infinite solutions" : "No solution";
        else
            return "x=" + to_string(-constant/coefficient);
    }
};

int main() {
    Solution solution;
    solution.solveEquation("x+5-3+x=6+x-2");
    return 0;
}
