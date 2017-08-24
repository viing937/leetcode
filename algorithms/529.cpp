#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int dx[8] = {1, -1, 0, 0, -1, -1, 1, 1};
    int dy[8] = {0, 0, 1, -1, -1, 1, -1, 1};
    void reveal(vector<vector<char>> &board, int x, int y) {
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return;
        }
        int m = board.size(), n = board[0].size();
        int cnt = 0;
        for (int i = 0; i < 8; i++) {
            int xx = x+dx[i], yy = y+dy[i];
            if (xx >= 0 && xx < m && yy >=0 && yy < n && board[xx][yy] == 'M')
                cnt += 1;
        }
        if (cnt != 0) {
            board[x][y] = '0' + cnt;
            return;
        }
        board[x][y] = 'B';
        for (int i = 0; i < 8; i++) {
            int xx = x+dx[i], yy = y+dy[i];
            if (xx >= 0 && xx < m && yy >=0 && yy < n && board[xx][yy] == 'E')
                reveal(board, xx, yy);
        }
        return;
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click) {
        reveal(board, click[0], click[1]);
        return board;
    }
};

int main() {
    return 0;
}
