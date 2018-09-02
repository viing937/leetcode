#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinStack
{
private:
    vector<int> mystack;
    vector<int> stackmin;
public:
    void push(int x)
    {
        if ( stackmin.empty() )
            stackmin.push_back(x);
        else
            stackmin.push_back(min(stackmin.back(), x));
        mystack.push_back(x);
    }
    void pop()
    {
        mystack.pop_back();
        stackmin.pop_back();
    }
    int top()
    {
        return mystack.back();
    }
    int getMin()
    {
        return stackmin.back();
    }
};

int main()
{
    return 0;
}
