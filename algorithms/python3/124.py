# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.rls = root.val
        self.helper(root)
        return self.rls

    def helper(self, root):
        if root.left and root.right:
            left = self.helper(root.left)
            right = self.helper(root.right)
            self.rls = max([self.rls, root.val, left, right, left+root.val, right+root.val, left+right+root.val])
            return max(root.val, left+root.val, right+root.val)
        elif root.left:
            left = self.helper(root.left)
            self.rls = max([self.rls, root.val, left, left+root.val])
            return max(root.val, left+root.val)
        elif root.right:
            right = self.helper(root.right)
            self.rls = max([self.rls, root.val, right, right+root.val])
            return max(root.val, right+root.val)
        else:
            self.rls = max([self.rls, root.val])
            return root.val
