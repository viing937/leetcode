#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> row(rowIndex+1, 0);
        row[0] = 1;
        for ( int i = 1; i <= rowIndex; i++ )
            for ( int j = i; j > 0; j-- )
                row[j] += row[j-1];
        for ( int i = 0; i < rowIndex/2; i++ )
            row[rowIndex-i] = row[i];
        return row;
    }
};

int main()
{
    Solution solution;
    for ( int k = 0; k < 5; k++ )
    {
        vector<int> result = solution.getRow(k);
        for ( int i = 0; i < (int)result.size(); i++ )
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
