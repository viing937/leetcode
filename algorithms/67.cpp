#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        unsigned int i;
        int carry = 0;
        for ( i = 0; i < a.size() && i < b.size(); i++ )
        {
            int sum = a[i]-'0'+b[i]-'0'+carry;
            ans.push_back(sum%2+'0');
            carry = sum/2;
        }
        while ( i < a.size() )
        {
            int sum = a[i]-'0'+carry;
            ans.push_back(sum%2+'0');
            carry = sum/2;
            i++;
        }
        while ( i < b.size() )
        {
            int sum = b[i]-'0'+carry;
            ans.push_back(sum%2+'0');
            carry = sum/2;
            i++;
        }
        if ( carry )
            ans.push_back(carry+'0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    return 0;
}
