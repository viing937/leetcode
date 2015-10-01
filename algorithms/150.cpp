#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> s;
        for ( auto item : tokens )
        {
            if ( item.size() > 1 || isdigit(item[0]) )
                s.push(stoi(item));
            else
            {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                switch ( item[0] )
                {
                    case '+': s.push(a+b); break;
                    case '-': s.push(a-b); break;
                    case '*': s.push(a*b); break;
                    case '/': s.push(a/b); break;
                }
            }
        }
        return s.top();
    }
};

int main()
{
    return 0;
}
