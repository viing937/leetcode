#include <iostream>
#include <queue>
using namespace std;

class Stack
{
private:
    queue<int> stack;
public:
    // Push element x onto stack.
    void push(int x)
    {
        stack.push(x);
        return;
    }

    // Removes the element on top of the stack.
    void pop()
    {
        queue<int> tmpData;
        while ( stack.size() > 1 )
        {
            tmpData.push(stack.front());
            stack.pop();
        }
        stack.pop();
        while ( !tmpData.empty() )
        {
            stack.push(tmpData.front());
            tmpData.pop();
        }
        return;
    }

    // Get the top element.
    int top()
    {
        queue<int> tmpData;
        while ( stack.size() > 1 )
        {
            tmpData.push(stack.front());
            stack.pop();
        }
        int returnVal = stack.front();
        tmpData.push(returnVal);
        stack.pop();
        while ( !tmpData.empty() )
        {
            stack.push(tmpData.front());
            tmpData.pop();
        }
        return returnVal;
    }

    // Return whether the stack is empty.
    bool empty()
    {
        return stack.empty();
    }
};

int main()
{
    return 0;
}
