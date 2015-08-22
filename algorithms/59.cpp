#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector< vector<int> > generateMatrix(int n)
    {
        vector< vector<int> > result(n, vector<int>(n, 0));
        if ( n == 0 )
            return result;
        int x = 0, y = 0, dir = 0, cnt = 1;
        while ( x >= 0 && x < n && y >= 0 && y < n && result[x][y] == 0 )
        {
            result[x][y] = cnt++;
            if ( dir == 0 )
            {
                if ( y+1 >= n || result[x][y+1] )
                {
                    dir = 1;
                    x += 1;
                }
                else
                    y += 1;
            }
            else if ( dir == 1 )
            {
                if ( x+1 >= n || result[x+1][y] )
                {
                    dir = 2;
                    y -= 1;
                }
                else
                    x += 1;
            }
            else if ( dir == 2 )
            {
                if ( y-1 < 0 || result[x][y-1] )
                {
                    dir = 3;
                    x -= 1;
                }
                else
                    y -= 1;
            }
            else if ( dir == 3 )
            {
                if ( x-1 < 0 || result[x-1][y] )
                {
                    dir = 0;
                    y += 1;
                }
                else
                    x -= 1;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
