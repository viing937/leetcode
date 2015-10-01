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
            if ( item == "+" )
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b+a);
            }
            else if ( item == "-" )
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b-a);
            }
            else if ( item == "*" )
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b*a);
            }
            else if ( item == "/" )
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b/a);
            }
            else
                s.push(stoi(item));
        }
        return s.top();
    }
};

int main()
{
    return 0;
}
