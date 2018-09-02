#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    unordered_map<char, int> hash_char;
    vector< vector<int> > state_transition;
public:
    Solution()
    {
        hash_char = {{' ', 0}, {'+', 1}, {'-', 1}, {'.', 2}, {'e', 3},
                     {'0', 4}, {'1', 4}, {'2', 4}, {'3', 4}, {'4', 4},
                     {'5', 4}, {'6', 4}, {'7', 4}, {'8', 4}, {'9', 4}};
        state_transition = {{ 0,  1,  3, -1,  2},
                            {-1,  1,  3, -1,  2},
                            { 8, -1,  4,  5,  2},
                            {-1, -1, -1, -1,  4},
                            { 8, -1, -1,  5,  4},
                            {-1,  6, -1, -1,  7},
                            {-1, -1, -1, -1,  7},
                            { 8, -1, -1, -1,  7},
                            { 8, -1, -1, -1, -1}};
    }
    bool isNumber(string s)
    {
        int current = 0;
        for ( unsigned int i = 0; i < s.size(); ++i )
        {
            if ( current == -1 )
                return false;
            if ( hash_char.find(s[i]) == hash_char.end() )
                return false;
            current = state_transition[current][hash_char[s[i]]];
        }
        if ( current == 2 || current == 4 || current == 7 || current == 8 )
            return true;
        else
            return false;
    }
};

int main()
{
    return 0;
}
