# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        rls, stack = [], []
        p = root
        while p or stack:
            while p:
                stack.append(p)
                p = p.left
            p = stack.pop()
            rls.append(p.val)
            p = p.right
        return rls
