# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        if not root: return []
        rls, cur = [], [0]
        def helper(node):
            cur.append(node.val)
            cur[0] += node.val
            if node.left or node.right:
                if node.left: helper(node.left)
                if node.right: helper(node.right)
            elif cur[0] == sum:
                rls.append(cur[1:])
            cur.pop()
            cur[0] -= node.val
        helper(root)
        return rls
