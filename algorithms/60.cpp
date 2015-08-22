#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> factorial(10, 1);
        for ( unsigned int i = 2; i < factorial.size(); ++i )
            factorial[i] = factorial[i-1]*i;
        vector<bool> visited(n+1, false);

        k -= 1;
        string result;
        for ( n -= 1; n >= 0; --n )
        {
            int c = k/factorial[n];
            int i;
            for ( i = 1; c >= 0; ++i )
            {
                if ( !visited[i] )
                    c -= 1;
            }
            visited[--i] = true;
            result.push_back('0'+i);
            k = k%factorial[n];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    cout << solution.getPermutation(3, 6) << endl;
    return 0;
}
