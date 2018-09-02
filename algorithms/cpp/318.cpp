#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<string>& words)
    {
        int len = words.size();
        vector<int> bits(len);
        for ( int i = 0; i < len; ++i )
        {
            int bit = 0;
            for ( char ch : words[i] )
                bit |= 1<<(ch-'a');
            bits[i] = bit;
        }
        int ans = 0;
        for ( int i = 0; i < len; ++i )
            for ( int j = i+1; j < len; ++j )
                if ( (bits[i]&bits[j]) == 0 )
                    ans = max(ans, (int)(words[i].size()*words[j].size()));
        return ans;
    }
};

int main()
{
    return 0;
}
