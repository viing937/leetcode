#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>> &board) {
        int result = 0;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.')
                    continue;
                if (j > 0 && board[i][j-1] == 'X')
                    continue;
                if (i > 0 && board[i-1][j] == 'X')
                    continue;
                result += 1;
            }
        }
        return result;
    }
};

int main() {
    return 0;
}
