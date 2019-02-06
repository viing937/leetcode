# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        def cutHead(head):
            remain = head.next
            head.next = None
            return head, remain
        def insertNode(head, node):
            if not head: return node
            if node.val < head.val:
                head, node.next = node, head
                return head
            p, q = head, head.next
            while q and node.val > q.val:
                p, q = q, q.next
            p.next, node.next = node, q
            return head

        if not head: return None
        rls = None
        while head:
            node, head = cutHead(head)
            rls = insertNode(rls, node)
        return rls
