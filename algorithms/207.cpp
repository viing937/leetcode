#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    bool dfs(vector< vector<int> > &graph, vector<bool> &visited, int node)
    {
        if ( visited[node] )
            return true;
        visited[node] = true;
        for ( auto it = graph[node].begin(); it != graph[node].end(); it++ )
            if ( dfs(graph, visited, *it) )
                return true;
        visited[node] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector< pair<int, int> >& prerequisites)
    {
        vector< vector<int> > graph(numCourses);
        vector<bool> visited(numCourses, false);
        for ( auto it = prerequisites.begin(); it != prerequisites.end(); it++ )
            graph[it->first].push_back(it->second);
        for ( int i = 0; i < numCourses; i++ )
            if ( dfs(graph, visited, i) )
                return false;
        return true;
    }
};

int main()
{
    return 0;
}
