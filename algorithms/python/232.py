class MyQueue:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.entryStack, self.exitStack = [], []

    def push(self, x):
        """
        Push element x to the back of queue.
        :type x: int
        :rtype: void
        """
        self.entryStack.append(x)

    def pop(self):
        """
        Removes the element from in front of queue and returns that element.
        :rtype: int
        """
        self.lazyTransfer()
        return self.exitStack.pop()

    def peek(self):
        """
        Get the front element.
        :rtype: int
        """
        self.lazyTransfer()
        return self.exitStack[-1]

    def empty(self):
        """
        Returns whether the queue is empty.
        :rtype: bool
        """
        return not self.entryStack and not self.exitStack

    def lazyTransfer(self):
        if not self.exitStack:
            while self.entryStack:
                self.exitStack.append(self.entryStack.pop())


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
