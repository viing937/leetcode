# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        if not headA or not headB: return None
        tail = headA
        while tail.next:
            tail = tail.next
        tail.next = headB

        slow, fast = headA, headA
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                break
        else:
            tail.next = None
            return None

        fast = headA
        while slow != fast:
            slow = slow.next
            fast = fast.next

        tail.next = None
        return fast
