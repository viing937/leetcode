# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        depth = self.countDepth(root.left)
        if depth == self.countDepthRight(root.left):
            left = 2 ** depth - 1
            return 1 + left + self.countNodes(root.right)
        else:
            right = 2 ** (depth-1) - 1
            return 1 + self.countNodes(root.left) + right

    def countDepth(self, root):
        depth = 0
        while root:
            depth += 1
            root = root.left
        return depth

    def countDepthRight(self, root):
        depth = 0
        while root:
            depth += 1
            root = root.right
        return depth
