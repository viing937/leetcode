#include <iostream>
#include <stack>
using namespace std;

class Queue
{
private:
    stack<int> s;
public:
    // Push element x to the back of queue.
    void push(int x)
    {
        s.push(x);
        return;
    }

    // Removes the element from in front of queue.
    void pop(void)
    {
        stack<int> tmp;
        while ( !s.empty() )
        {
            tmp.push(s.top());
            s.pop();
        }
        tmp.pop();
        while ( !tmp.empty() )
        {
            s.push(tmp.top());
            tmp.pop();
        }
        return;
    }

    // Get the front element.
    int peek(void)
    {
        stack<int> tmp;
        while ( !s.empty() )
        {
            tmp.push(s.top());
            s.pop();
        }
        int val = tmp.top();
        while ( !tmp.empty() )
        {
            s.push(tmp.top());
            tmp.pop();
        }
        return val;
    }

    // Return whether the queue is empty.
    bool empty(void)
    {
        return s.empty();
    }
};

int main()
{
    return 0;
}
