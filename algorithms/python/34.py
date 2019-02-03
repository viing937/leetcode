from bisect import bisect_left
class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        left = bisect_left(nums, target)
        right = bisect_left(nums, target+1)
        if left >= len(nums) or nums[left] != target:
            return [-1, -1]
        else:
            return [left, right-1]
