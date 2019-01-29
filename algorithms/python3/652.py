# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import defaultdict

class Solution(object):
    def findDuplicateSubtrees(self, root):
        """
        :type root: TreeNode
        :rtype: List[TreeNode]
        """
        if not root: return []
        count = defaultdict(int)
        nodeDict = {}
        def helper(node):
            left = helper(node.left) if node.left else None
            right = helper(node.right) if node.right else None
            cur = (left, (node.val, ), right)
            count[cur] += 1
            nodeDict[cur] = node
            return cur
        helper(root)

        rls = []
        for k, v in count.items():
            if v > 1:
                rls.append(nodeDict[k])
        return rls
