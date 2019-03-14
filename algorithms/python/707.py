class LinkedNode():
    def __init__(self, value):
        self.val = value
        self.prev = self.next = None

class MyLinkedList(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.length = 0
        self.head, self.tail = LinkedNode(0), LinkedNode(0)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.curIdx, self.curNode = -1, self.head

    def touch(self, index):
        dis = abs(self.curIdx - index)
        if index < dis:
            self.curIdx, self.curNode = -1, self.head
        if self.length - index < dis:
            self.curIdx, self.curNode = self.length, self.tail
        while self.curIdx < index and self.curNode.next:
            self.curIdx += 1
            self.curNode = self.curNode.next
        while self.curIdx > index and self.curNode.prev:
            self.curIdx -= 1
            self.curNode = self.curNode.prev

    def get(self, index):
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        :type index: int
        :rtype: int
        """
        if index < 0 or index >= self.length: return -1
        self.touch(index)
        return self.curNode.val

    def addAtHead(self, val):
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        :type val: int
        :rtype: void
        """
        self.addAtIndex(0, val)

    def addAtTail(self, val):
        """
        Append a node of value val to the last element of the linked list.
        :type val: int
        :rtype: void
        """
        self.addAtIndex(self.length, val)

    def addAtIndex(self, index, val):
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        :type index: int
        :type val: int
        :rtype: void
        """
        if index < 0 or index > self.length: return
        node = LinkedNode(val)
        self.touch(index-1)
        p, q = self.curNode, self.curNode.next
        node.prev, p.next = p, node
        node.next, q.prev = q, node
        self.length += 1

    def deleteAtIndex(self, index):
        """
        Delete the index-th node in the linked list, if the index is valid.
        :type index: int
        :rtype: void
        """
        if index < 0 or index >= self.length: return
        self.touch(index-1)
        p, q = self.curNode, self.curNode.next.next
        p.next, q.prev = q, p
        self.length -= 1


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
