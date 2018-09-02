#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector< vector<int> >& matrix, int target)
    {
        int row = 0, col = matrix[0].size()-1;
        while ( row < (int)matrix.size() && col >= 0 )
        {
            if ( matrix[row][col] == target ) return true;
            else if ( matrix[row][col] < target ) row += 1;
            else if ( matrix[row][col] > target ) col -= 1;
        }
        return false;
    }
};

int main()
{
    return 0;
}
