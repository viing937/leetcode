# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import copy
from itertools import product

class Solution:
    def allPossibleFBT(self, N):
        """
        :type N: int
        :rtype: List[TreeNode]
        """
        if N % 2 == 0:
            return []
        m = {1: [TreeNode(0)]}
        for i in range(3, N+1, 2):
            m[i] = []
            for l in range(1, i, 2):
                r = i-1-l
                for left, right in product(m[l], m[r]):
                    root = TreeNode(0)
                    # root.left = copy.deepcopy(left)
                    # root.right = copy.deepcopy(right)
                    root.left = left
                    root.right = right
                    m[i].append(root)
        return m[N]
