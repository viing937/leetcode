class Solution:
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        rls = len(nums)+1
        l, t = 0, 0
        for i in range(len(nums)):
            t += nums[i]
            while t-nums[l] >= s:
                t -= nums[l]
                l += 1
            if t >= s:
                rls = min(rls, i-l+1)
        if rls > len(nums):
            return 0
        else:
            return rls
