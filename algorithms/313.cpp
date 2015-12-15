#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int>& primes)
    {
        vector<int> ugly(1, 1);
        set< pair<int, int> > heap;
        for ( unsigned int i = 0; i < primes.size(); ++i )
            heap.insert(make_pair(primes[i], 0));
        while ( n > (int)ugly.size() )
        {
            auto it = heap.begin();
            int num = it->first;
            int idx = it->second;
            if ( num != ugly.back() )
                ugly.push_back(num);
            heap.insert(make_pair(num/ugly[idx]*ugly[idx+1], idx+1));
            heap.erase(it);
        }
        return ugly.back();
    }
};

int main()
{
    int n = 12;
    vector<int> primes = {2, 7, 13, 19};
    Solution solution;
    cout << solution.nthSuperUglyNumber(n, primes) << endl;
    return 0;
}
