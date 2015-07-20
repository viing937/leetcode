#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    bool dfs(vector< vector<int> > &graph, vector<int> &visited, int node)
    {
        if ( visited[node] == 1 )
            return true;
        visited[node] = 1;
        for ( auto it = graph[node].begin(); it != graph[node].end(); it++ )
            if ( dfs(graph, visited, *it) )
                return true;
        visited[node] = 2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector< pair<int, int> >& prerequisites)
    {
        vector< vector<int> > graph(numCourses);
        vector<int> visited(numCourses, 0);
        for ( auto it = prerequisites.begin(); it != prerequisites.end(); it++ )
            graph[it->first].push_back(it->second);
        for ( int i = 0; i < numCourses; i++ )
            if ( visited[i] == 0 && dfs(graph, visited, i) )
                return false;
        return true;
    }
};

int main()
{
    return 0;
}
