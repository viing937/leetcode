#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
    void dfs(vector< vector<char> > &board, int x, int y)
    {
        board[x][y] = '!';
        for ( int i = 0; i < 4; ++i )
            if ( x+dx[i] > 0 && x+dx[i] < (int)board.size()-1 &&
                 y+dy[i] > 0 && y+dy[i] < (int)board[0].size()-1 &&
                 board[x+dx[i]][y+dy[i]] == 'O' )
                dfs(board, x+dx[i], y+dy[i]);
        return;
    }
public:
    void solve(vector< vector<char> >& board)
    {
        if ( board.size() <= 2 || board[0].size() <= 2 )
            return;
        int m = board.size(), n = board[0].size();
        for ( int i = 0; i < m; ++i )
        {
            if ( board[i][0] == 'O' )
                dfs(board, i, 0);
            if ( board[i][n-1] == 'O' )
                dfs(board, i, n-1);
        }
        for ( int i = 0; i < n; ++i )
        {
            if ( board[0][i] == 'O' )
                dfs(board, 0, i);
            if ( board[m-1][i] == 'O' )
                dfs(board, m-1, i);
        }
        for ( int i = 0; i < m; ++i )
            for ( int j = 0; j < n; ++j )
                if ( board[i][j] == '!' )
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
        return;
    }
};

int main()
{
    return 0;
}
