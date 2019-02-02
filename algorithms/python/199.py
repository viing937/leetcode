# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        rls = []
        if not root:
            return rls
        self.helper(root, 0, rls)
        return rls

    def helper(self, root, depth, rls):
        if depth >= len(rls):
            rls.append(root.val)
        else:
            rls[depth] = root.val
        if root.left:
            self.helper(root.left, depth+1, rls)
        if root.right:
            self.helper(root.right, depth+1, rls)
