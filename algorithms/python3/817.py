# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def numComponents(self, head, G):
        """
        :type head: ListNode
        :type G: List[int]
        :rtype: int
        """
        G = set(G)
        rls, flag = 0, False
        while head:
            if head.val in G:
                rls += 1 if not flag else 0
                flag = True
            else:
                flag = False
            head = head.next
        return rls
