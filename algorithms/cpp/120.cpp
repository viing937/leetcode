#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector< vector<int> >& triangle)
    {
        for ( unsigned int i = 1; i < triangle.size(); ++i )
        {
            triangle[i][0] += triangle[i-1].front();
            for ( unsigned int j = 1; j < triangle[i].size()-1; ++j )
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            triangle[i][i] += triangle[i-1].back();
        }
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};

int main()
{
    return 0;
}
