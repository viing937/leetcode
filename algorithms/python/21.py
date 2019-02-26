# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if not l1: return l2
        elif not l2: return l1
        if l1.val > l2.val:
            l1, l2 = l2, l1
        p = l1
        while l2:
            while p.next and p.next.val < l2.val:
                p = p.next
            node, l2 = l2, l2.next
            p.next, node.next = node, p.next
        return l1
