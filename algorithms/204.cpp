#include <stdio.h>
#include <vector>
using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> isPrime(n, true);
        vector<int> prime;
        for ( int i = 2; i < n; i++ )
        {
            if ( isPrime[i] )
                prime.push_back(i);
            for ( auto it = prime.begin(); it != prime.end(); it++ )
            {
                if ( *it * i >= n )
                    break;
                isPrime[*it*i] = false;
                if ( i % *it == 0 )
                    break;
            }
        }
        return prime.size();
    }
};

int main()
{
    return 0;
}
