class Solution:
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        for i in range(n):
            while nums[i] >= 1 and nums[i] <= n and nums[nums[i]-1] != nums[i]:
                # Warning: The Order Is Important in Python!
                nums[nums[i]-1], nums[i]  = nums[i], nums[nums[i]-1]
        for i in range(n):
            if nums[i] != i+1:
                return i+1
        return n+1
