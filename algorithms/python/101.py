# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def isEqual(a, b):
            if a and b:
                return a.val == b.val and isEqual(a.left, b.right) and isEqual(a.right, b.left)
            elif not a and not b:
                return True
            else:
                return False
        if root:
            return isEqual(root.left, root.right)
        else:
            return True
