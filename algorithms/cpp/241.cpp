#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<int> cal(int start, int end, string &input)
    {
        vector<int> product;
        if ( find_if_not(input.begin()+start, input.begin()+end, (int(*)(int))std::isdigit) == input.begin()+end )
        {
            int t = 0;
            for ( int i = start; i < end; ++i )
                t = t*10+input[i]-'0';
            product.push_back(t);
            return product;
        }
        for ( int i = start; i < end; ++i )
        {
            if ( isdigit(input[i]) )
                continue;
            auto left = cal(start, i, input),
                 right = cal(i+1, end, input);
            for ( auto left_item : left )
            {
                for ( auto right_item : right )
                {
                    switch ( input[i] )
                    {
                        case '+': product.push_back(left_item+right_item); break;
                        case '-': product.push_back(left_item-right_item); break;
                        case '*': product.push_back(left_item*right_item); break;
                    }
                }
            }
        }
        return product;
    }
public:
    vector<int> diffWaysToCompute(string input)
    {
        return cal(0, input.size(), input);
    }
};

int main()
{
    Solution solution;
    solution.diffWaysToCompute("1+2+3");
    return 0;
}
