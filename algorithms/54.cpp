#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector< vector<int> >& matrix)
    {
        vector<int> result;
        if ( matrix.size() <= 0 )
            return result;
        vector< vector<bool> > visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        int x = 0, y = 0, dir = 0;
        while ( x >= 0 && x < (int)matrix.size() && y >= 0 && y < (int)matrix[0].size() && !visited[x][y] )
        {
            result.push_back(matrix[x][y]);
            visited[x][y] = true;
            if ( dir == 0 )
            {
                if ( y+1 >= (int)matrix[x].size() || visited[x][y+1] )
                {
                    dir = 1;
                    x += 1;
                }
                else
                    y += 1;
            }
            else if ( dir == 1 )
            {
                if ( x+1 >= (int)matrix.size() || visited[x+1][y] )
                {
                    dir = 2;
                    y -= 1;
                }
                else
                    x += 1;
            }
            else if ( dir == 2 )
            {
                if ( y-1 < 0 || visited[x][y-1] )
                {
                    dir = 3;
                    x -= 1;
                }
                else
                    y -= 1;
            }
            else if ( dir == 3 )
            {
                if ( x-1 < 0 || visited[x-1][y] )
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
