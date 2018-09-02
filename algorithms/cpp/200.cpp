#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    void dfs(vector< vector<char> > &grid, vector< vector<bool> > &visited, int x, int y)
    {
        visited[x][y] = true;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for ( int i = 0; i < 4; ++i )
            if ( x+dx[i] >= 0 && x+dx[i] < (int)grid.size() &&
                 y+dy[i] >= 0 && y+dy[i] < (int)grid[0].size() &&
                 !visited[x+dx[i]][y+dy[i]] && grid[x+dx[i]][y+dy[i]] == '1' )
                dfs(grid, visited, x+dx[i], y+dy[i]);
    }
public:
    int numIslands(vector< vector<char> >& grid)
    {
        if ( grid.empty() )
            return 0;
        vector< vector<bool> > visited(grid.size(), vector<bool>(grid[0].size(), false));
        int result = 0;
        for ( unsigned int i = 0; i < grid.size(); ++i )
        {
            for ( unsigned int j = 0; j < grid[0].size(); ++j )
            {
                if ( !visited[i][j] && grid[i][j] == '1' )
                {
                    result += 1;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
