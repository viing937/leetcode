class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        k %= len(nums)
        nums[0:-k] = nums[0:-k][::-1]
        nums[-k:] = nums[-k:][::-1]
        nums[:] = nums[::-1]
