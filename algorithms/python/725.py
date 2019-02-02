# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def splitListToParts(self, root, k):
        """
        :type root: ListNode
        :type k: int
        :rtype: List[ListNode]
        """
        l = self.getLength(root)
        ps = l // k
        parts = []
        for i in range(l%k):
            node, root = self.getK(root, ps+1)
            parts.append(node)
        for i in range(l%k, k):
            node, root = self.getK(root, ps)
            parts.append(node)
        return parts

    def getK(self, root, k):
        if k == 0:
            return None, root
        p, q, k = root, root.next, k-1
        while k:
            p, q, k = q, q.next, k-1
        p.next = None
        return root, q

    def getLength(self, root):
        length = 0
        while root:
            length += 1
            root = root.next
        return length
