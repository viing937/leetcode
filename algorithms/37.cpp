#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<bool>> row, col;
    vector<vector<vector<bool>>> subgrid;
    bool helper(vector<vector<char>> &board, int pos) {
        if (pos >= 81)
            return true;
        int x = pos/9, y = pos%9;
        if (board[x][y] != '.')
            return helper(board, pos+1);
        for (int num = 1; num <= 9; num++) {
            if (!row[x][num] && !col[y][num] && !subgrid[x/3][y/3][num]) {
                row[x][num] = col[y][num] = subgrid[x/3][y/3][num] = true;
                board[x][y] = '0'+num;
                if (helper(board, pos+1))
                    return true;
                row[x][num] = col[y][num] = subgrid[x/3][y/3][num] = false;
                board[x][y] = '.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>> &board) {
        row = vector<vector<bool>>(9, vector<bool>(10, false));
        col = vector<vector<bool>>(9, vector<bool>(10, false));
        subgrid = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(10, false)));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j]-'0';
                row[i][num] = col[j][num] = subgrid[i/3][j/3][num] = true;
            }
        }
        helper(board, 0);
    }
};

int main() {
    return 0;
}
