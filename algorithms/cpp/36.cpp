#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector< vector<char> >& board)
    {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int block[3][3][9] = {0};
        for ( int i = 0; i < 9; i++ )
        {
            for ( int j = 0; j < 9; j++ )
            {
                if ( board[i][j] != '.')
                {
                    if ( row[i][board[i][j]-'1'] || col[j][board[i][j]-'1'] || block[i/3][j/3][board[i][j]-'1'] )
                        return false;
                    row[i][board[i][j]-'1'] = 1;
                    col[j][board[i][j]-'1'] = 1;
                    block[i/3][j/3][board[i][j]-'1'] = 1;
                }
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}
