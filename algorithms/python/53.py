class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = nums[:]
        for i in range(1, len(dp)):
            dp[i] = max(nums[i], dp[i-1]+nums[i])
        return max(dp)
