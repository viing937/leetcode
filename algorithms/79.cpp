#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int dx[4] = {+1, -1, 0, 0}, dy[4] = {0, 0, +1, -1};
    bool dfs(vector< vector<char> > &board, string &word, int x, int y, int cur)
    {
        if ( cur == (int)word.size() )
            return true;
        for ( int i = 0; i < 4; ++i )
        {
            if ( x+dx[i] >= 0 && x+dx[i] < (int)board.size() &&
                 y+dy[i] >= 0 && y+dy[i] < (int)board[0].size() &&
                 board[x+dx[i]][y+dy[i]] == word[cur] )
            {
                board[x+dx[i]][y+dy[i]] = 0;
                bool res = dfs(board, word, x+dx[i], y+dy[i], cur+1);
                board[x+dx[i]][y+dy[i]] = word[cur];
                if ( res ) return true;
            }
        }
        return false;
    }
public:
    bool exist(vector< vector<char> >& board, string word)
    {
        if ( board.size() == 0 || board[0].size() == 0 )
            return false;
        int m = board.size(), n = board[0].size();
        for ( int i = 0; i < m; ++i )
            for ( int j = 0; j < n; ++j )
                if ( board[i][j] == word[0] )
                {
                    board[i][j] = 0;
                    bool res = dfs(board, word, i, j, 1);
                    board[i][j] = word[0];
                    if ( res ) return true;
                }
        return false;
    }
};

int main()
{
    vector< vector<char> > board(1, vector<char>(2, 'a'));
    string word = "aaa";
    Solution solution;
    if ( solution.exist(board, word) )
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
