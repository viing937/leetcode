#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector< vector<char> >& board)
    {
        int arr[10];
        for ( unsigned int i = 0; i < board.size(); i++ )
        {
            memset(arr, 0, sizeof(arr));
            for ( unsigned int j = 0; j < board[i].size(); j++ )
            {
                if ( board[i][j] >= '0' && board[i][j] <= '9' )
                {
                    if ( arr[board[i][j]-'0'] )
                        return false;
                    else
                        arr[board[i][j]-'0'] = 1;
                }
            }
        }
        for ( unsigned int i = 0; i < board[0].size(); i++ )
        {
            memset(arr, 0, sizeof(arr));
            for ( unsigned int j = 0; j < board.size(); j++ )
            {
                if ( board[j][i] >= '0' && board[j][i] <= '9' )
                {
                    if ( arr[board[j][i]-'0'] )
                        return false;
                    else
                        arr[board[j][i]-'0'] = 1;
                }
            }
        }
        for ( unsigned int i = 0; i < board.size(); i += 3 )
        {
            for ( unsigned int j = 0; j < board[i].size(); j += 3 )
            {
                memset(arr, 0, sizeof(arr));
                for ( int m = 0; m < 3; m++ )
                {
                    for ( int n = 0; n < 3; n++ )
                    {
                        if ( board[i+m][j+n] >= '0' && board[i+m][j+n] <= '9' )
                        {
                            if ( arr[board[i+m][j+n]-'0'] )
                                return false;
                            else
                                arr[board[i+m][j+n]-'0'] = 1;
                        }
                    }
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
