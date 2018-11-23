# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True

        if root.left:
            l = root.left
            while l.right:
                l = l.right
            if l.val >= root.val:
                return False

        if root.right:
            r = root.right
            while r.left:
                r = r.left
            if r.val <= root.val:
                return False

        return self.isValidBST(root.left) and self.isValidBST(root.right)
