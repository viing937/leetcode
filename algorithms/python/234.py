# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        def findMid(head):
            slow, fast = head, head
            while slow and fast and fast.next:
                slow = slow.next
                fast = fast.next.next
            return slow
        def rev(head):
            if not head: return None
            rls, head = head, head.next
            rls.next = None
            while head:
                node, head = head, head.next
                rls, node.next = node, rls
            return rls

        if not head: return True
        mid = findMid(head)
        mid = rev(mid)
        while mid:
            if head.val != mid.val:
                return False
            head, mid = head.next, mid.next
        return True
