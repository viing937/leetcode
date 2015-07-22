#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector< pair<int, int> >& prerequisites)
    {
        vector< vector<int> > graph(numCourses);
        vector<int> dependences(numCourses, 0);
        for ( auto it = prerequisites.begin(); it != prerequisites.end(); it++ )
        {
            graph[it->second].push_back(it->first);
            dependences[it->first]++;
        }
        vector<int> result;
        queue<int> q;
        for ( int i = 0; i < numCourses; i++ )
            if ( dependences[i] == 0 )
                q.push(i);
        int cnt = numCourses;
        while ( !q.empty() )
        {
            cnt--;
            int current = q.front();
            q.pop();
            result.push_back(current);
            for ( auto it = graph[current].begin(); it != graph[current].end(); it++ )
            {
                dependences[*it]--;
                if ( dependences[*it] == 0 )
                    q.push(*it);
            }
        }
        if ( cnt != 0 )
            result.clear();
        return result;
    }
};

int main()
{
    return 0;
}
