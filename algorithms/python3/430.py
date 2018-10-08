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
        if not head:
            return None

        child = self.flatten(head.child)
        forward = self.flatten(head.next)
        head.child, head.next = None, None

        cur = head
        if child:
            cur.next, child.prev = child, cur
            while cur.next:
                cur = cur.next

        cur.next = forward
        if forward:
            forward.prev = cur
        return head
