#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int>& citations)
    {
        sort(citations.begin(), citations.end());
        int len = citations.size(), i = len-1;
        while ( i >= 0 && citations[i] >= len-i )
            i -= 1;
        return len-i-1;
    }
};

int main()
{
    return 0;
}
