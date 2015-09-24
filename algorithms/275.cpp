#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int>& citations)
    {
        int len = citations.size();
        if ( len == 0 || citations[len-1] <= 0 )
            return 0;
        int l = 0, r = len-1;
        while ( l < r )
        {
            int mid = (l+r)/2;
            if ( citations[mid] > len-mid )
                r = mid;
            else if ( citations[mid] < len-mid )
                l = mid+1;
            else
                return len-mid;
        }
        return len-l;
    }
};

int main()
{
    return 0;
}
