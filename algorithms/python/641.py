class DequeNode:
    def __init__(self, x):
        self.val = x
        self.prev = None
        self.next = None

class MyCircularDeque:
    def __init__(self, k):
        """
        Initialize your data structure here. Set the size of the deque to be k.
        :type k: int
        """
        self.size, self.maxSize = 0, k
        self.head, self.tail = None, None

    def insertFront(self, value):
        """
        Adds an item at the front of Deque. Return true if the operation is successful.
        :type value: int
        :rtype: bool
        """
        if self.size >= self.maxSize: return False
        node = DequeNode(value)
        if self.size == 0:
            self.head, self.tail = node, node
        else:
            node.next, self.head.prev = self.head, node
            self.head = node
        self.size += 1
        return True

    def insertLast(self, value):
        """
        Adds an item at the rear of Deque. Return true if the operation is successful.
        :type value: int
        :rtype: bool
        """
        if self.size >= self.maxSize: return False
        node = DequeNode(value)
        if self.size == 0:
            self.head, self.tail = node, node
        else:
            node.prev, self.tail.next = self.tail, node
            self.tail = node
        self.size += 1
        return True

    def deleteFront(self):
        """
        Deletes an item from the front of Deque. Return true if the operation is successful.
        :rtype: bool
        """
        if self.size == 0: return False
        if self.size == 1:
            self.head, self.tail = None, None
        else:
            self.head = self.head.next
            self.head.prev = None
        self.size -= 1
        return True

    def deleteLast(self):
        """
        Deletes an item from the rear of Deque. Return true if the operation is successful.
        :rtype: bool
        """
        if self.size == 0: return False
        if self.size == 1:
            self.head, self.tail = None, None
        else:
            self.tail = self.tail.prev
            self.tail.next = None
        self.size -= 1
        return True

    def getFront(self):
        """
        Get the front item from the deque.
        :rtype: int
        """
        if self.head:
            return self.head.val
        else:
            return -1

    def getRear(self):
        """
        Get the last item from the deque.
        :rtype: int
        """
        if self.tail:
            return self.tail.val
        else:
            return -1

    def isEmpty(self):
        """
        Checks whether the circular deque is empty or not.
        :rtype: bool
        """
        return self.size == 0

    def isFull(self):
        """
        Checks whether the circular deque is full or not.
        :rtype: bool
        """
        return self.size == self.maxSize

# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
