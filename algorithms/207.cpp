#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector< pair<int, int> >& prerequisites)
    {
        vector< vector<bool> > graph(numCourses, vector<bool>(numCourses, false));
        for ( auto it = prerequisites.begin(); it != prerequisites.end(); it++ )
            graph[it->first][it->second] = true;
        for ( int k = 0; k < numCourses; k++ )
            for ( int i = 0; i < numCourses; i++ )
                for ( int j = 0; j < numCourses; j++ )
                    if ( graph[i][k] && graph[k][j] )
                        graph[i][j] = true;
        for ( int i = 0; i < numCourses; i++ )
            if ( graph[i][i] )
                return false;
        return true;
    }
};

int main()
{
    return 0;
}
