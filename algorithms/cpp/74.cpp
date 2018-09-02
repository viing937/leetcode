#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int binaryRow(int l, int r, vector< vector<int> > &matrix, int target)
    {
        if ( l > r )
            return -1;
        int m = (l+r)/2;
        if ( matrix[m].front() <= target && matrix[m].back() >= target )
            return m;
        else if ( matrix[m].front() > target )
            return binaryRow(l, m-1, matrix, target);
        else
            return binaryRow(m+1, r, matrix, target);
    }
    bool binaryCol(int l, int r, vector< vector<int> > &matrix, int target, int row)
    {
        if ( l > r )
            return false;
        int m = (l+r)/2;
        if ( matrix[row][m] == target )
            return true;
        else if ( matrix[row][m] > target )
            return binaryCol(l, m-1, matrix, target, row);
        else
            return binaryCol(m+1, r, matrix, target, row);
    }
public:
    bool searchMatrix(vector< vector<int> >& matrix, int target)
    {
        int row = binaryRow(0, matrix.size()-1, matrix, target);
        if ( row == -1 )
            return false;
        else
            return binaryCol(0, matrix[0].size()-1, matrix, target, row);
    }
};

int main()
{
    return 0;
}
