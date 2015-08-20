#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        vector<char> result;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int product;
        int carry;
        for ( int i = 0; i < (int)num1.size(); ++i )
        {
            carry = 0;
            for ( int j = 0; j < (int)num2.size(); ++j )
            {
                if ( i+j >= (int)result.size() )
                    result.push_back('0');
                product = ((result[i+j]-'0')+(num1[i]-'0')*(num2[j]-'0')+carry)%10;
                carry = ((result[i+j]-'0')+(num1[i]-'0')*(num2[j]-'0')+carry)/10;
                result[i+j] = product+'0';
            }
            if ( carry )
                result.push_back(carry+'0');
        }
        reverse(result.begin(), result.end());
        string s(result.begin(), result.end());
        for ( int i = 0; i < (int)s.size(); ++i )
            if ( s[i] != '0' )
                return s.substr(i);
        return "0";
    }
};

int main()
{
    Solution solution;
    cout << solution.multiply("12312", "0") << endl;
    return 0;
}
