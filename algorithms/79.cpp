#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    bool dfs(vector< vector<char> > &board, string &word, vector< vector<bool> > &visited, int x, int y, int cur)
    {
        if ( cur == (int)word.size() )
            return true;
        if ( x+1 < (int)board.size() && !visited[x+1][y] && board[x+1][y] == word[cur] )
        {
            visited[x+1][y] = true;
            if ( dfs(board, word, visited, x+1, y, cur+1) ) return true;
            visited[x+1][y] = false;
        }
        if ( x-1 >= 0 && !visited[x-1][y] && board[x-1][y] == word[cur] )
        {
            visited[x-1][y] = true;
            if ( dfs(board, word, visited, x-1, y, cur+1) ) return true;
            visited[x-1][y] = false;
        }
        if ( y+1 < (int)board[0].size() && !visited[x][y+1] && board[x][y+1] == word[cur] )
        {
            visited[x][y+1] = true;
            if ( dfs(board, word, visited, x, y+1, cur+1) ) return true;
            visited[x][y+1] = false;
        }
        if ( y-1 >= 0 && !visited[x][y-1] && board[x][y-1] == word[cur] )
        {
            visited[x][y-1] = true;
            if ( dfs(board, word, visited, x, y-1, cur+1) ) return true;
            visited[x][y-1] = false;
        }
        return false;
    }
public:
    bool exist(vector< vector<char> >& board, string word)
    {
        if ( board.size() == 0 || board[0].size() == 0 )
            return false;
        int m = board.size(), n = board[0].size();
        vector< vector<bool> > visited(m, vector<bool>(n, false));
        for ( int i = 0; i < m; ++i )
            for ( int j = 0; j < n; ++j )
                if ( board[i][j] == word[0] )
                {
                    visited[i][j] = true;
                    if ( dfs(board, word, visited, i, j, 1) ) return true;
                    visited[i][j] = false;
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
