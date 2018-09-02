#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int count(vector< vector<int> > &board, int x, int y)
    {
        int row = board.size(), col = board[0].size();
        int cnt = 0;
        for ( int i = x-1; i <= x+1; ++i )
            for ( int j = y-1; j <= y+1; ++j )
                if ( i >= 0 && i < row && j >= 0 && j < col )
                    cnt += board[i][j]&1;
        cnt -= board[x][y]&1;
        return cnt;
    }
public:
    void gameOfLife(vector< vector<int> >& board)
    {
        int row = board.size(), col = board[0].size();
        for ( int i = 0; i < row; ++i )
            for ( int j = 0; j < col; ++j )
                board[i][j] = board[i][j]|(count(board, i, j)<<1);
        for ( int i = 0; i < row; ++i )
        {
            for ( int j = 0; j < col; ++j )
            {
                int cnt = board[i][j]>>1;
                if ( cnt < 2 || cnt > 3 )
                    board[i][j] = 0;
                else if ( cnt == 2 )
                    board[i][j] = board[i][j]&1;
                else if ( cnt == 3 )
                    board[i][j] = 1;
            }
        }
        return;
    }
};

int main()
{
    return 0;
}
