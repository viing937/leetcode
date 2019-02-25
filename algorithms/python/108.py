# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if len(nums) == 0: return None
        idx = len(nums) // 2
        node = TreeNode(nums[idx])
        node.left = self.sortedArrayToBST(nums[:idx])
        node.right = self.sortedArrayToBST(nums[idx+1:])
        return node
