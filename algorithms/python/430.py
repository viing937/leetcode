"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""
class Solution(object):
    def flatten(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        head, tail = self.helper(head)
        return head

    def helper(self, head):
        if not head:
            return None, None

        childHead, childTail = self.helper(head.child)
        nextHead, nextTail = self.helper(head.next)
        head.child, head.next = None, None
        tail = head

        if childHead:
            tail.next, childHead.prev = childHead, tail
            tail = childTail

        if nextHead:
            tail.next, nextHead.prev = nextHead, tail
            tail = nextTail

        return head, tail
