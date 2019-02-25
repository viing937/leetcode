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
        def helper(nums):
            if len(nums) == 0: return None
            idx = len(nums) // 2
            node = TreeNode(nums[idx])
            node.left = helper(nums[:idx])
            node.right = helper(nums[idx+1:])
            return node
        return helper(nums)
