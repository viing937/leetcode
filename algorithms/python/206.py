# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head: return None

        def helper(head):
            if not head.next:
                return head, head
            node, head = head, head.next
            node.next = None
            head, tail = helper(head)
            tail.next = node
            return head, node
        head, tail = helper(head)
        return head
