# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        """
        if not head or not head.next:
            return head
        p, q = head, head.next
        q.next, p.next = p, self.swapPairs(q.next)
        return q
